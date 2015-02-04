# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FusionInventory-Agent
PORTVERSION=	2.3.15
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GROUSSE
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Agent for OCS Inventory server and FusionInventory for GLPI servers

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-ExtUtils-MakeMaker>=6.59:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-libwww>=5.8:${PORTSDIR}/www/p5-libwww \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-XML-TreePP>=0.26:${PORTSDIR}/textproc/p5-XML-TreePP \

RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Proxy>=0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-HTTP-Server-Simple-Authen>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple-Authen \
		p5-IO-Capture>=0:${PORTSDIR}/devel/p5-IO-Capture \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \

OPTIONS_DEFINE=	CUPS DAEMON DEPLOY HTTP ZLIB SSL DMIDECODE PCIUTILS NMAP WOL
OPTIONS_DEFAULT=	ZLIB DMIDECODE PCIUTILS
DAEMON_DESC=	Daemon mode
HTTP_DESC=	Local HTTP daemon
ZLIB_DESC=	Zlib compression
DMIDECODE_DESC=	Dmidecode hardware information
PCIUTILS_DESC=	Pciutils hardware information
WOL_DESC=	Wake on LAN support

USES=		gmake perl5
USE_PERL5=	configure

CUPS_RUN_DEPENDS=	p5-Net-CUPS>=0.6:${PORTSDIR}/print/p5-Net-CUPS
DAEMON_RUN_DEPENDS=	p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
			p5-Proc-PID-File>=0:${PORTSDIR}/devel/p5-Proc-PID-File
DEPLOY_RUN_DEPENDS=	p5-Archive-Extract>=0:${PORTSDIR}/archivers/p5-Archive-Extract \
			p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
			p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
			p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
			p5-URI-Escape-XS>=0:${PORTSDIR}/www/p5-URI-Escape-XS \
			p5-POE-Component-Client-Ping>=0:${PORTSDIR}/net/p5-POE-Component-Client-Ping
HTTP_RUN_DEPENDS=	p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon
ZLIB_RUN_DEPENDS=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.14:${PORTSDIR}/security/p5-IO-Socket-SSL \
			p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https
DMIDECODE_RUN_DEPENDS=	dmidecode:${PORTSDIR}/sysutils/dmidecode
PCIUTILS_RUN_DEPENDS+=	lspci:${PORTSDIR}/sysutils/pciutils
NMAP_RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap
WOL_RUN_DEPENDS=	p5-Net-Write>=0:${PORTSDIR}/net/p5-Net-Write

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name '*.orig' \) -delete

.include <bsd.port.mk>
