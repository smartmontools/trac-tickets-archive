#
# smartd mailer script
#
# Copyright (C) 2016 Christian Franke
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# You should have received a copy of the GNU General Public License
# (for example COPYING); If not, see <http://www.gnu.org/licenses/>.
#
# $Id$
#

# Parse command line and check environment
$dryrun = $false
if (($args.Count -eq 1) -and ($args[0] -eq "--dryrun")) {
  $dryrun = $true
}

$toCsv = $env:SMARTD_ADDRCSV
$subject = $env:SMARTD_SUBJECT
$file = $env:SMARTD_FULLMSGFILE

if (!((($args.Count -eq 0) -or $dryrun) -and $toCsv -and $subject -and $file)) {
  echo `
"smartd mailer script

Usage:
set SMARTD_ADDRCSV='Comma separated mail addresses'
set SMARTD_SUBJECT='Mail Subject'
set SMARTD_FULLMSGFILE='X:\PATH\TO\Message.txt'

.\$($MyInvocation.MyCommand.Name) [--dryrun]
"
  exit 1
}

# Read configuration
$from = "smartd daemon <root@$($env:COMPUTERNAME.ToLower()).local>"
. .\smartd_mailer.conf.ps1
if (!$?) { exit 1 }

# Create parameters
$to = $toCsv.Split(",")
$body = Get-Content -Path $file | Out-String

$parm = @{
  SmtpServer = $smtpServer; From = $from; To = $to
  Subject = $subject; Body = $body
}
if ($port) {
  $parm += @{ Port = $port }
}
if ($useSsl) {
  $parm += @{ useSsl = $true }
}

if ($username -and ($password -or $passwordSecure)) {
  if (!$passwordSecure) {
    $secureString = ConvertTo-SecureString -String $password -AsPlainText -Force
  } else {
    $secureString = ConvertTo-SecureString -String $passwordSecure
  }
  $credential = New-Object -Typename System.Management.Automation.PSCredential -Argumentlist $username,$secureString
  $parm += @{ Credential = $credential }
}

# Send mail
if ($dryrun) {
  echo "Send-MailMessage" @parm
} else {
  Send-MailMessage @parm
  if (!$?) { exit 1 }
}
