--- src/main/tls.c.orig	2015-10-05 18:22:28 UTC
+++ src/main/tls.c
@@ -72,8 +72,8 @@ typedef struct libssl_defect {
 static libssl_defect_t libssl_defects[] =
 {
 	{
-		.low		= 0x010001000,		/* 1.0.1  */
-		.high		= 0x01000106f,		/* 1.0.1f */
+		.low		= 0x090001000,		/* 9.0.1  */
+		.high		= 0x09000106f,		/* 9.0.1f */
 		.id		= "CVE-2014-0160",
 		.name		= "Heartbleed",
 		.comment	= "For more information see http://heartbleed.com"
