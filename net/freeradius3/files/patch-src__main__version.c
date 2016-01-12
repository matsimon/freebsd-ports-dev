--- src/main/version.c.orig	2015-10-05 18:22:28 UTC
+++ src/main/version.c
@@ -62,8 +62,7 @@ int ssl_check_consistency(void)
 		ERROR("libssl version mismatch.  built: %lx linked: %lx",
 		      (unsigned long) ssl_built,
 		      (unsigned long) ssl_linked);
-
-		return -1;
+		return 0;
 	}
 
 	/*
