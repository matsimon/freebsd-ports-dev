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

OPTIONS_GROUP=		DOCS
OPTIONS_GROUP_DOCS=	CHI CHM DOT HTML PDF PS RTF XML

OPTIONS_DEFINE=		PROPRIETARY DTRACE MAN JSON SNMP DOCS
OPTIONS_DEFAULT=	PROPRIETARY MAN

# Descriptions
PROPRIETARY_DESC=	Proprietary protocols (CDP/EDP/FDP/SONMP)
SNMP_DESC=		Enable the use of SNMP
DTRACE_DESC=		DTrace support
CHM_DESC=		Generate doxygen compressed HTML help documentation
CHI_DESC=		Generate doxygen seperate compressed HTML help index
DOT_DESC=		Generate graphics for doxygen documentation
MAN_DESC=		Generate doxygen manual pages
RTF_DESC=		Generate doxygen RTF documentation
XML_DESC=		Generate doxygen XML documentation
HTML_DESC=		Generate doxygen plain HTML documentation
PDF_DESC=		Generate doxygen PDF documentation
PS_DESC=		Generate doxygen PostScript documentation

# Features
DTRACE_CONFIGURE_ENABLE=	dtrace
JSON_CONFIGURE_WITH=		json
SNMP_CONFIGURE_ENABLE=		snmp
XML_CONFIGURE_WITH=		xml

# Documentation
CHI_CONFIGURE_ENABLE=	doxygen-chi
CHM_CONFIGURE_ENABLE=	doxygen-chm
DOT_CONFIGURE_ENABLE=	doxygen-dot
HTML_CONFIGURE_ENABLE=	doxygen-html
MAN_CONFIGURE_ENABLE=	doxygen-man
PDF_CONFIGURE_ENABLE=	doxygen-ps
PS_CONFIGURE_ENABLE=	doxygen-pdf
RTF_CONFIGURE_ENABLE=	doxygen-rtf
XML_CONFIGURE_ENABLE=	doxygen-xml

# Feature-induced dependencies
XML_RUN_DEPENDS=	libxml2:${PORTSDIR}/textproc/libxml2
SNMP_RUN_DEPENDS=	net-snmp:${PORTSDIR}/net-mgmt/net-snmp
JSON_BUILD_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf
JSON_RUN_DEPENDS=	jansson>=2:${PORTSDIR}/devel/jansson
CHI_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
CHM_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOT_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
HTML_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
MAN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
PDF_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
PS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
RTF_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
XML_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

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
