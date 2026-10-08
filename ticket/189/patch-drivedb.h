--- drivedb.h.orig	2010-10-14 08:47:49.000000000 -0700
+++ drivedb.h	2011-07-14 23:09:40.000000000 -0700
@@ -1290,6 +1290,11 @@
     "ST3(250[68]2|32062|40062|50063|75064)0NS",
     "", "", ""
   },
+  { "Seagate Barracuda ES.2", // unaffected firmware
+    "ST3(25031|50032|75033|100034)0NS",
+    "MA(0[^7]|[^0].)", // http://dellfirmware.seagate.com/dell_firmware/DellFirmwareRequest.jsp?locale=EN
+    "", ""
+  },
   { "Seagate Barracuda ES.2", // fixed firmware
     "ST3(25031|50032|75033|100034)0NS",
     "SN[01]6", // http://seagate.custkb.com/seagate/crm/selfservice/search.jsp?DocId=207963
