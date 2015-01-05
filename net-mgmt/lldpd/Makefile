# Created by: Mathieu Simon <freebsd@simweb.ch>
# $FreeBSD$

PORTNAME=	lldpd
PORTVERSION=	0.7.13
CATEGORIES=	net-mgmt
MASTER_SITES=	http://media.luffy.cx/files/${PORTNAME}/

MAINTAINER=	freebsd@simweb.ch
COMMENT=	LLDP (802.1ab)/CDP/EDP/SONMP/FDP daemon and SNMP subagent

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_SUB=	yes

USE_RC_SUBR=	lldpd

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-privsep \
		--with-privsep-chroot=/var/empty \
		--with-lldpd-ctl-socket=/var/run/lldpd.socket \
		--with-lldpd-pid-file=/var/run/lldpd.pid \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

USERS=	_lldpd
GROUPS=	_lldpd

OPTIONS_DEFINE=		BASH DOCS DTRACE JSON PROPRIETARY READLINE SNMP XML ZSH
OPTIONS_DEFAULT=	BASH JSON PROPRIETARY SNMP XML

DTRACE_DESC=		DTrace support
JSON_DESC=		JSON output support
PROPRIETARY_DESC=	Support proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable the use of SNMP
XML_DESC=		XML output support

DTRACE_CONFIGURE_ENABLE=	dtrace
JSON_CONFIGURE_WITH=		json
READLINE_CONFIGURE_WITH=	readline
SNMP_CONFIGURE_WITH=		snmp
XML_CONFIGURE_WITH=		xml

JSON_BUILD_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf
JSON_LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp \
			libnetsnmpagent.so:${PORTSDIR}/net-mgmt/net-snmp \
			libnetsnmpmibs.so:${PORTSDIR}/net-mgmt/net-snmp
XML_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

post-stage:
	@${CP} ${FILESDIR}/README.bsd ${STAGEDIR}${DOCSDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROPRIETARY}
CONFIGURE_ARGS+=--enable-cdp --enable-edp --enable-fdp --enable-sonmp
.else
CONFIGURE_ARGS+=--disable-cdp --disable-edp --disable-fdp --disable-sonmp
.endif

.include <bsd.port.mk>
