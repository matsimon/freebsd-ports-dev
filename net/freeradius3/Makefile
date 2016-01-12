# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeradius
DISTVERSION=	3.0.10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	3
DISTNAME=	freeradius-server-${DISTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Free RADIUS server implementation

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libtalloc.so:${PORTSDIR}/devel/talloc

LOGDIR?=	/var/log

CONFLICTS_INSTALL=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].* \
			freeradius-mysql-[0-9].* freeradius-[^3].*

USE_RC_SUBR=	radiusd

USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	src/modules/rlm_counter/rad_counter scripts/sql/radsqlrelay
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-udpfromto
# Prevent /root/.rnd leftover
MAKE_ARGS+=	HOME=/dev/null
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${DISTVERSION} LIBVER=0${PORTVERSION:C/\./0/g}

OPTIONS_DEFINE=		DOCS LDAP LIBWBCLIENT MEMCACHED MYSQL PERL PGSQL PYTHON \
			REDIS REST SQLITE3 UNIXODBC YUBIKEY
OPTIONS_GROUP=		EXP
OPTIONS_GROUP_EXP=	EXPDB EXPMOD IDN
OPTIONS_RADIO=		KRB
OPTIONS_RADIO_KRB=	HEIMDAL HEIMDAL_PORT KERBEROS
OPTIONS_DEFAULT=	HEIMDAL PERL

OPTIONS_SUB=	yes

EXP_DESC=		Experimental modules
EXPDB_DESC=		Experimental DB Backends (Firebird, FreeTDS)
EXPMOD_DESC=		Experimental modules (SMSOTP, Example)
HEIMDAL_DESC=		With Heimdal Kerberos support
HEIMDAL_PORT_DESC=	With Heimdal Kerberos support from ports
IDN_DESC=		International Domain Names support
LIBWBCLIENT_DESC=	Use Samba libwbclient for faster MS-CHAP
MEMCACHED_DESC=		Support caching with memcached as backend
REST_DESC=		Enable RESTful API support
UNIXODBC_DESC=		With unixODBC database support
YUBIKEY_DESC=		With Yubikey support

EXPDB_CONFIGURE_WITH=	rlm_sql_firebird rlm_freetds
EXPDB_LIB_DEPENDS=	libct.so:${PORTSDIR}/databases/freetds
EXPDB_USE=		FIREBIRD=yes

# MIT must be be absent, else build fails. See upstream issue #1466
HEIMDAL_CONFIGURE_ON=		--with-rlm_krb5 --with-rlm-krb5-dir=/
HEIMDAL_CONFLICTS_BUILD=	krb5-[0-9].*

HEIMDAL_PORT_LIB_DEPENDS=	libkrb5.so.26:${PORTSDIR}/security/heimdal
HEIMDAL_PORT_CONFIGURE_ON=	--with-rlm_krb5 \
				--with-rlm-krb5-dir=${LOCALBASE}

IDN_CONFIGURE_WITH=		rlm_idn
IDN_LIB_DEPENDS=		libidn.so:${PORTSDIR}/dns/libidn

KERBEROS_LIB_DEPENDS=		libkrb5.so.3:${PORTSDIR}/security/krb5
KERBEROS_CONFIGURE_ON=		--with-rlm_krb5 \
				--with-rlm-krb5-dir=${LOCALBASE}

LDAP_CONFIGURE_WITH=		rlm_ldap edir
LDAP_LIB_DEPENDS=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
LDAP_USE=			OPENLDAP=yes

LIBWBCLIENT_CONFIGURE_ON=	--with-winbind-include-dir=${LOCALBASE}/include/samba4
LIBWBCLIENT_LIB_DEPENDS=	libwbclient.so:${PORTSDIR}/net/samba42

MEMCACHED_CONFIGURE_WITH=	rlm_cache_memcached
MEMCACHED_LIB_DEPENDS=		libmemcached.so:${PORTSDIR}/databases/libmemcached

MYSQL_CONFIGURE_WITH=		rlm_sql_mysql
MYSQL_USE=			MYSQL=yes

PERL_CONFIGURE_WITH=		rlm_perl
PERL_CONFIGURE_ON=		--with-perl
PERL_USES=			perl5

PGSQL_CONFIGURE_WITH=		rlm_sql_postgresql
PGSQL_USES=			pgsql

PYTHON_USES=			python
PYTHON_CONFIGURE_WITH=		rlm_python
PYTHON_CONFIGURE_ON=		--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
				--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR}

REDIS_CONFIGURE_WITH=		rlm_redis rlm_rediswho
REDIS_LIB_DEPENDS=		libhiredis.so:${PORTSDIR}/databases/hiredis

REST_CONFIGURE_WITH=		rlm_rest libcurl=${LOCALBASE}
REST_LIB_DEPENDS=		libjson-c.so:${PORTSDIR}/devel/json-c \
				libcurl.so:${PORTSDIR}/ftp/curl

SQLITE3_CONFIGURE_WITH=		rlm_sql_sqlite
SQLITE3_LIB_DEPENDS=		libsqlite3.so:${PORTSDIR}/databases/sqlite3

UNIXODBC_CONFIGURE_WITH=	rlm_sql_unixodbc
UNIXODBC_LIB_DEPENDS=		libodbc.so:${PORTSDIR}/databases/unixODBC

YUBIKEY_CONFIGURE_WITH=		rlm_yubikey
YUBIKEY_LIB_DEPENDS=		libykclient.so:${PORTSDIR}/security/ykclient

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

LDAP_VARS=	_REQUIRE+=slapd
MYSQL_VARS=	_REQUIRE+=mysql
PGSQL_VARS=	_REQUIRE+=postgresql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHEIMDAL} || ${PORT_OPTIONS:MHEIMDAL_PORT} || ${PORT_OPTIONS:MKERBEROS}
PLIST_SUB+=	 KRB5=""
.else
PLIST_SUB+=	KRB5="@comment "
.endif

.if ${PORT_OPTIONS:MEXPMOD}
EXPM=		yes
PLIST_SUB+=	EXPMOD=""
.else
PLIST_SUB+=	EXPMOD="@comment "
.endif

.if ${PORT_OPTIONS:MEXPDB}
EXPM=		yes
PLIST_SUB+=	EXPDB=""
.else
PLIST_SUB+=	EXPDB="@comment "
.endif

# IDN module is still experimental
.if ${PORT_OPTIONS:MIDN}
EXPM=		yes
.endif

# If at least one experimental module is enabled, extra parameter is needed
.if defined(EXPM)
CONFIGURE_ARGS+=--with-experimental-modules \
		--without-rlm_couchbase \
		--without-rlm_ruby
.else
CONFIGURE_ARGS+=--without-experimental-modules
.endif

.include <bsd.port.pre.mk>

# if we're installing, place sample configs into ${EXAMPLESDIR}
MAKE_ARGS+=	raddbdir="${EXAMPLESDIR}/raddb" R=${STAGEDIR}

FREERADIUS_LIBDIR=	lib/freeradius-${PORTVERSION}
PLIST_SUB+=	LIBDIR="${FREERADIUS_LIBDIR}"
USE_LDCONFIG=	${PREFIX}/${FREERADIUS_LIBDIR}

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--without-docdir
PLIST_SUB+=	PORTDOCS="@comment "
SUB_LIST+=	PORTDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}
PLIST_SUB+=	PORTDOCS=""
SUB_LIST+=	PORTDOCS=""
.endif

CONFIGURE_ARGS+=--with-logdir=${LOGDIR} \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB} \
		--prefix=${PREFIX} --libdir=${PREFIX}/${FREERADIUS_LIBDIR} \
		--localstatedir=/var \
		--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_oracle \
		--without-rlm_securid \
		--with-vmps \
		--with-collectdclient-lib-dir=/dev/null

SUB_FILES+=	pkg-install pkg-message
SUB_LIST+=	RADDB_WORK="${WRKSRC}/raddb" \
		RADDB="${PREFIX}/etc/raddb" \
		LOGDIR="${LOGDIR}" \
		LIBDIR="${PREFIX}/${FREERADIUS_LIBDIR}"
SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
# never try to find execinfo.h (needed until we can enable/disable backtrace
	@${REINPLACE_CMD} -e '/#include <execinfo.h>/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -Ee "s:tests/all.mk ::" ${WRKSRC}/src/all.mk
	@${CP} ${WRKSRC}/m4/ax_with_prog.m4 ${WRKSRC}
# Patch raddb/certs/Makefile for the full path to the openssl binary (using
# ports OpenSSL if installed)
	@${REINPLACE_CMD} -E \
		-e "s:^([[:space:]])+openssl:\1${OPENSSLBASE}/bin/openssl:g" \
		${WRKSRC}/raddb/certs/Makefile
	@${REINPLACE_CMD} -Ee 's: ..R...sbindir./rc.radiusd : :' \
		${WRKSRC}/scripts/all.mk

post-build:
	@${FIND} ${WRKSRC}/build/lib -type f -name '*.so' -exec ${STRIP_CMD} {} \;
	@${FIND} ${WRKSRC}/build/bin -type f -exec ${STRIP_CMD} {} \;

.include <bsd.port.post.mk>
