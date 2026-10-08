--- scsicmds.h.orig	2017-10-18 22:25:44 UTC
+++ scsicmds.h
@@ -304,7 +304,7 @@ Documentation, see http://www.storage.ib
 
 
 /* SCSI command timeout values (units are seconds) */
-#define SCSI_TIMEOUT_DEFAULT    20  // should be longer than the spin up time
+#define SCSI_TIMEOUT_DEFAULT    60  // should be longer than the spin up time
                                     // of a disk in standby mode.
 #define SCSI_TIMEOUT_SELF_TEST  (5 * 60 * 60)   /* allow max 5 hours for */
                                             /* extended foreground self test */
