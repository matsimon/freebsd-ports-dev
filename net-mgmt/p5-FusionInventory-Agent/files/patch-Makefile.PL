--- Makefile.PL.orig	2015-01-07 13:32:40.362923025 +0100
+++ Makefile.PL	2015-01-07 09:26:49.025369341 +0100
@@ -206,11 +196,7 @@
 
 config_install :
 	install -d -m 755 $(DESTDIR)$(SYSCONFDIR)
-	if [ -f $(DESTDIR)/$(SYSCONFDIR)/agent.cfg ]; then \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg.new; \
-	else \
-	    install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg; \
-	fi
+	install -m 644 etc/agent.cfg $(DESTDIR)$(SYSCONFDIR)/agent.cfg.sample
 
 data_install :
 	install -d -m 755 $(DESTDIR)$(DATADIR)
