# Created by: Mathieu Simon <freebsd@simweb.ch>
# $FreeBSD$

PORTNAME=	lldpd
PORTVERSION=	0.7.12
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
		--with-privsep-chroot=/var/run/lldpd
INSTALL_TARGET=	install-strip

USERS=	_lldpd
GROUPS=	_lldpd

OPTIONS_DEFINE=		DTRACE JSON MAN PROPRIETARY READLINE SNMP XML
OPTIONS_DEFAULT=	PROPRIETARY MAN

# Descriptions
DTRACE_DESC=		DTrace support
MAN_DESC=		Install manpages
PROPRIETARY_DESC=	Proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable the use of SNMP
XML_DESC=		XML output via libxml2

# Features
DTRACE_CONFIGURE_ENABLE=	dtrace
JSON_CONFIGURE_WITH=		json
READLINE_CONFIGURE_WITH=	readline
SNMP_CONFIGURE_ENABLE=		snmp
XML_CONFIGURE_WITH=		xml

# Feature-induced dependencies
XML_BUILD_DEPENDS=	libxml2:${PORTSDIR}/textproc/libxml2
XML_LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
SNMP_RUN_DEPENDS=	net-snmp:${PORTSDIR}/net-mgmt/net-snmp
JSON_BUILD_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf \
			jansson:${PORTSDIR}/devel/jansson
JSON_RUN_DEPENDS=	libjansson.so>=2:${PORTSDIR}/devel/jansson

post-stage:
	@${MKDIR} ${STAGEDIR}/var/run/lldpd
	${CP} ${STAGEDIR}${PREFIX}/lib/pkgconfig/* \
	${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROPRIETARY}
CONFIGURE_ARGS+=--enable-cdp --enable-edp --enable-fdp --enable-sonmp
.else
CONFIGURE_ARGS+=--disable-cdp --disable-edp --disable-fdp --disable-sonmp
.endif

.include <bsd.port.mk>
