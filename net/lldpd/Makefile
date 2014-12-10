# Created by: Mathieu Simon <freebsd@simweb.ch>
# $FreeBSD$

PORTNAME=	lldpd
PORTVERSION=	0.7.12
CATEGORIES=	net
MASTER_SITES=	http://media.luffy.cx/files/${PORTNAME}/

MAINTAINER=	freebsd@simweb.ch
COMMENT=	LLDP (802.1ab)/CDP/EDP/SONMP/FDP daemon and SNMP subagent

LICENSE=	ISCL

RUN_DEPENDS=	libevent2>=2.0.5:${PORTSDIR}/devel/libevent2

USE_RC_SUBR=	lldpd

GNU_CONFIGURE=	yes

USERS=	_lldpd
GROUPS=	_lldpd

OPTIONS_GROUP= 		PROTO DOCS
OPTIONS_GROUP_PROTO=	LLDP-MED DOT1 DOT3 CDP EDP FDP SONMP
OPTIONS_GROUP_DOCS=	DOXY_DOT DOXY_MAN DOXY_RTF DOXY_XML DOXY_CHM \
			DOXY_CHI DOXY_HTML DOXY_PS DOXY_PDF

OPTIONS_DEFINE=	SNMP DTRACE XML JSON PRIVSEP
OPTIONS_DEFAULT= CDP EDP FDP SONMP LLDP-MED DOT1 DOT3 PRIVSEP

# Descriptions
PROTO_DESC=	Discovery Protocols
CDP_DESC=	Cisco Discovery Protocol
EDP_DESC=	Extreme Discovery Protocol
FDP_DESC=	Foundry Discovery Protocol
SONMP_DESC=	SynOptics Network Management Protocol
LLDP-MED_DESC=	LLDP-MED extension
DOT1_DESC=	Dot1 extension (VLAN stuff)
DOT3_DESC=	Dot3 extension (PHY stuff)
SNMP_DESC=	Enable the use of SNMP
DTRACE_DESC=	DTrace support
PRIVSEP_DESC=	Enable Privilege separation
DOXY_DOT_DESC=	Generate graphics for doxygen documentation
DOXY_MAN_DESC=	Generate doxygen manual pages
DOXY_RTF_DESC=	Generate doxygen RTF documentation
DOXY_XML_DESC=	Generate doxygen XML documentation
DOXY_CHM_DESC=	Generate doxygen compressed HTML help documentation
DOXY_CHI_DESC=	Generate doxygen seperate compressed HTML help index
DOXY_HTML_DESC=	Generate doxygen plain HTML documentation
DOXY_PS_DESC=	Generate doxygen PostScript documentation
DOXY_PDF_DESC=	Generate doxygen PDF documentation

# Protocol support
CDP_CONFIGURE_ENABLE=		cdp
DOT1_CONFIGURE_ENABLE=		dot1
DOT3_CONFIGURE_ENABLE=		dot3
EDP_CONFIGURE_ENABLE=		edp
FDP_CONFIGURE_ENABLE=		fdp
LLDP-MED_CONFIGURE_ENABLE=	lldpmed
SONMP_CONFIGURE_ENABLE=		sonmp

# Features
DTRACE_CONFIGURE_ENABLE=	dtrace
JSON_CONFIGURE_WITH=		json
PRIVSEP_CONFIGURE_ENABLE=	privsep
SNMP_CONFIGURE_ENABLE=		snmp
XML_CONFIGURE_WITH=		xml

# Documentation
DOXY_CHI_CONFIGURE_ENABLE=	doxygen-chi
DOXY_CHM_CONFIGURE_ENABLE=	doxygen-chm
DOXY_DOT_CONFIGURE_ENABLE=	doxygen-dot
DOXY_HTML_CONFIGURE_ENABLE=	doxygen-html
DOXY_MAN_CONFIGURE_ENABLE=	doxygen-man
DOXY_PDF_CONFIGURE_ENABLE=	doxygen-ps
DOXY_PS_CONFIGURE_ENABLE=	doxygen-pdf
DOXY_RTF_CONFIGURE_ENABLE=	doxygen-rtf
DOXY_XML_CONFIGURE_ENABLE=	doxygen-xml

# Feature-induced dependencies
XML_RUN_DEPENDS=	libxml2:${PORTSDIR}/textproc/libxml2
SNMP_RUN_DEPENDS=	net-snmp:${PORTSDIR}/net-mgmt/net-snmp
JSON_BUILD_DEPENDS=	pkgconf:${PORTSDIR}/devel/pkgconf
JSON_RUN_DEPENDS=	jansson>=2:${PORTSDIR}/devel/jansson
DOXY_CHI_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_CHM_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_DOT_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_HTML_BUILD_DEPENDS=doxygen:${PORTSDIR}/devel/doxygen
DOXY_MAN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_PDF_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_PS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_RTF_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOXY_XML_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen

post-stage:
	@${MKDIR} ${STAGEDIR}${PREFIX}/var/run/lldpd

.include <bsd.port.mk>
