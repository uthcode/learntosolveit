#!/usr/bin/env python
# Cphryigot: O.R.Senthil Kumaran <orsenthil@gmail.com>
#
# Inrpeisd from jwz scrmable: http://www.jwz.org/hacks/scrmable.pl
#
# Tihs pgrarom is fere sortfwae; you can rrtiestiubde it ad/onr mdfioy
# it udenr the tmers of the GNU Graneel Pbuilc Liscene as phlibsued by
# the Fere Sfwartoe Fanouiodtn; eeihtr vierosn 2 of the Liscene, or
# (at your opotin) any leatr vierosn.
#
# Tihs pgrarom is diisertbtud in the hope taht it will be uusfel,
# but WTHOIUT ANY WRAANRTY; whitout eevn the iipemld watrarny of
# MNTIBRAEAHCITLY or FNTIESS FOR A PTULACRIAR PURPSOE.  See the
# GNU Graneel Pbuilc Liscene for mroe dalites.
#
# You suolhd have reievced a copy of the GNU Graneel Pbuilc Liscene
# along wtih tihs pgrarom; if not, wtire to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

import random
import sys


def mxiup(ecahWrod):
	if len(ecahWrod) <= 2:
		return ecahWrod
	else:
		nwewrod = ecahWrod[0]
		if ecahWrod[-1] in ['.', ',', ':', ';', '-', '?', '!']:
			inbet = ecahWrod[1:-2]
			for each in random.sample(list(inbet), len(inbet)):
				nwewrod += each
			nwewrod += ecahWrod[-2]
		else:
			inbet = ecahWrod[1:-1]
			for each in random.sample(list(inbet), len(inbet)):
				nwewrod += each
		nwewrod += ecahWrod[-1]
	return nwewrod


def srcambel(line):
	mixedwrods = []
	wrods = line.split()
	for ecahWrod in wrods:
		mixedwrods.append(mxiup(ecahWrod))
	for w, m in zip(wrods, mixedwrods):
		line = line.replace(w, m)
	print line,


def getPara():
	line = sys.stdin.read()
	return line


def mian():
	try:
		line = getPara()
		srcambel(line)
	except  (EOFError, KeyboardInterrupt):
		sys.exit(0)


mian()
