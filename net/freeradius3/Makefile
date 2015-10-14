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

OPTIONS_DEFINE=		USER LDAP MYSQL \
			PGSQL UNIXODBC REDIS PYTHON EXPERIMENTAL \
			EDIR PERL REST SSL_PORT DOCS SQLITE3
OPTIONS_GROUP=		EXP
OPTIONS_GROUP_EXP=	FIREBIRD FREETDS IDN
OPTIONS_RADIO=		KRB
OPTIONS_RADIO_KRB=	HEIMDAL HEIMDAL_PORT KERBEROS
OPTIONS_DEFAULT=	USER PERL

OPTIONS_SUB=	yes

USER_DESC=		Run as user freeradius, group freeradius
HEIMDAL_DESC=		With Heimdal Kerberos support
HEIMDAL_PORT_DESC=	With Heimdal Kerberos from ports
UNIXODBC_DESC=		With unixODBC database support
FIREBIRD_DESC=		With Firebird database support
FREETDS_DESC=		With FreeTDS database support
EXP_DESC=		Build experimental modules
EXPERIMENTAL_DESC=	Build experimental modules
EDIR_DESC=		Enable eDirectory support (implies LDAP)
REST_DESC=		Enable RESTful API support
SSL_PORT_DESC=		Use OpenSSL from the ports collection
IDN_DESC=		International Domain Names support

EDIR_CONFIGURE_WITH=	with-edir

FIREBIRD_CONFIGURE_WITH=rlm_sql_firebird
FIREBIRD_USE=		FIREBIRD=yes

FREETDS_CONFIGURE_WITH=	rlm_freetds
FREETDS_LIB_DEPENDS=	libct.so:${PORTSDIR}/databases/freetds

HEIMDAL_CONFIGURE_ON=	--with-rlm_krb5 --with-rlm-krb5-dir=/

HEIMDAL_PORT_LIB_DEPENDS=libkrb5.so.26:${PORTSDIR}/security/heimdal
HEIMDAL_PORT_CONFIGURE_ON=	--with-rlm_krb5 \
				--with-rlm-krb5-dir=${LOCALBASE}

IDN_CONFIGURE_WITH=	rlm_idn
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

KERBEROS_LIB_DEPENDS=	libkrb5.so.3:${PORTSDIR}/security/krb5
KERBEROS_CONFIGURE_ON=	--with-rlm_krb5 \
			--with-rlm-krb5-dir=${LOCALBASE}

LDAP_CONFIGURE_WITH=	rlm_ldap
LDAP_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
LDAP_USE=		OPENLDAP=yes

MYSQL_CONFIGURE_WITH=	rlm_sql_mysql
MYSQL_USE=		MYSQL=yes

PERL_CONFIGURE_WITH=	rlm_perl
PERL_CONFIGURE_ON=	--with-perl
PERL_USES=		perl5

PGSQL_CONFIGURE_WITH=	rlm_sql_postgresql
PGSQL_USES=		pgsql

PYTHON_USES=		python
PYTHON_CONFIGURE_WITH=	with-rlm_python
PYTHON_CONFIGURE_ON=	--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
			--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR}

REDIS_CONFIGURE_WITH=	rlm_redis rlm_rediswho
REDIS_LIB_DEPENDS=	libhiredis.so:${PORTSDIR}/databases/hiredis

REST_CONFIGURE_WITH=	rlm_rest libcurl=${LOCALBASE} \
REST_CONFIGURE_ON=	--with-jsonc-lib-dir=${LOCALBASE}/lib \
			--with-jsonc-include-dir=${LOCALBASE}/include
REST_LIB_DEPENDS=	libjson-c.so:${PORTSDIR}/devel/json-c \
			libcurl.so:${PORTSDIR}/ftp/curl

SQLITE3_CONFIGURE_WITH=	rlm_sql_sqlite
SQLITE3_LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

UNIXODBC_CONFIGURE_WITH=rlm_sql_unixodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

LDAP_VARS=	_REQUIRE+=slapd
MYSQL_VARS=	_REQUIRE+=mysql
PGSQL_VARS=	_REQUIRE+=postgresql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSER}
SUB_LIST+=	RUN_AS_USER="yes"
.else
SUB_LIST+=	RUN_AS_USER="no"
.endif

# User and group to use if USER option is chosen
RADIUS_USER=	freeradius
RADIUS_GROUP=	freeradius

USERS=		${RADIUS_USER}
GROUPS=		${RADIUS_GROUP}

.if ${PORT_OPTIONS:MHEIMDAL} || ${PORT_OPTIONS:MHEIMDAL_PORT} || ${PORT_OPTIONS:MKERBEROS}
PLIST_SUB+=    KRB5=""
.else
PLIST_SUB+=    KRB5="@comment "
.endif

.if ${PORT_OPTIONS:MEDIR} && empty(PORT_OPTIONS:MLDAP)
PORT_OPTIONS+=	LDAP
.endif

# Firebird module is still experimental
.if ${PORT_OPTIONS:MFIREBIRD} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# freetds module is still experimental
.if ${PORT_OPTIONS:MFREETDS} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# IDN module is still experimental
.if ${PORT_OPTIONS:MIDN} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# Notes:
# --without-rlm_couchbase:
# With 3.0.10 when any or one certain experimental modules were enabled it
# wanted to configure rlm_couchbase.
# As long as it's unsupported by the port, explicitely disable it.
#
# --without-rlm_ruby:
# Last checked with 3.0.10: rlm_ruby's code contains a large warning that it
# leaks memory. That's why it was explicitely disabled.
.if ${PORT_OPTIONS:MEXPERIMENTAL} || defined(EXPM)
CONFIGURE_ARGS+=--with-experimental-modules \
                --without-rlm_couchbase \
		--without-rlm_ruby
PLIST_SUB+=	EXPM=""
.else
CONFIGURE_ARGS+=--without-experimental-modules
PLIST_SUB+=	EXPM="@comment "
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=yes
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

# This conditionality avoids -L/usr/lib in the radiusd build step when
# building with base system OpenSSL
.if ${OPENSSLLIB} != "/usr/lib"
CONFIGURE_ARGS+=--with-openssl-libraries=${OPENSSLLIB}
.endif
CONFIGURE_ARGS+=--with-logdir=${LOGDIR} \
		--with-openssl-includes=${OPENSSLINC} \
		--prefix=${PREFIX} --libdir=${PREFIX}/${FREERADIUS_LIBDIR} \
		--localstatedir=/var \
		--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_yubikey \
		--without-rlm_sql_oracle \
		--without-rlm_securid \
		--without-rlm_cache_memcached \
		--with-vmps \
		--with-collectdclient-lib-dir=/dev/null

.if ${ARCH} == amd64
CONFIGURE_ARGS+=--with-pic
.endif

SUB_FILES+=	pkg-install pkg-message
SUB_LIST+=	RADIUS_USER="${RADIUS_USER}" \
		RADIUS_GROUP="${RADIUS_GROUP}" \
		RADDB_WORK="${WRKSRC}/raddb" \
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
