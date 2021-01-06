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


def mxiup(ecah_wrod):
    if len(ecah_wrod) <= 2:
        return ecah_wrod
    else:
        nwewrod = ecah_wrod[0]
        if ecah_wrod[-1] in ['.', ',', ':', ';', '-', '?', '!']:
            inbet = ecah_wrod[1:-2]
            for each in random.sample(list(inbet), len(inbet)):
                nwewrod += each
            nwewrod += ecah_wrod[-2]
        else:
            inbet = ecah_wrod[1:-1]
            for each in random.sample(list(inbet), len(inbet)):
                nwewrod += each
        nwewrod += ecah_wrod[-1]
    return nwewrod


def srcambel(line):
    mixedwrods = []
    wrods = line.split()
    for ecah_wrod in wrods:
        mixedwrods.append(mxiup(ecah_wrod))
    for w, m in zip(wrods, mixedwrods):
        line = line.replace(w, m)
    print(line, end='')


def getgraparaph():
    line = sys.stdin.read()
    return line


def mian():
    try:
        line = getgraparaph()
        srcambel(line)
    except (EOFError, KeyboardInterrupt):
        sys.exit(0)


mian()
