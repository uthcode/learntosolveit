#! /usr/local/bin/python --

"""
usage: %(progname)s [args]
 
   --cat [files]  -- categorize a bunch of files

      mp3info(filename)
        - reads the mp3 header and returns a dictionary containing
          these fields:

          VERSION
          MM - number of minutes
          SS - number of seconds
          STEREO - 0-mono, 1-stereo
          LAYER - MPEG layer 2 or 3
          MODE 
          COPYRIGHT
          BITRATE 
          FREQUENCY

      get_mp3tag(filename)
        - finds the id3 tag of the mp3 and returns a dictionary
          containing these fields: TITLE, ARTIST, ALBUM, YEAR, COMMENT

      get_xing_header(filename)
        - returns the XING header (flags, frames, bytes) of the mp3 or
          None.

      Categorize(fn)
        - creates a directory called 'cats' with three subdirectories
          'GENRE_ARTIST', 'GENRE', and 'ARTIST'.  It reads the ID3 tag
          off of the mp3 and creates a three symlinks in this
          directory structure.  All files without ID3 tags will have a
          genre and artist of 'Unknown'.


"""

import os, sys, string, time, getopt

mp3_genres = ['Blues',  'Classic Rock',  'Country',  'Dance',  
	      'Disco',  'Funk',  'Grunge',  'Hip-Hop',  'Jazz',  
	      'Metal',  'New Age',  'Oldies',  'Other',  'Pop',  
	      'R&B',  'Rap',  'Reggae',  'Rock',  'Techno',  
	      'Industrial',  'Alternative',  'Ska',  'Death Metal',  
	      'Pranks',  'Soundtrack',  'Euro-Techno',  'Ambient',  
	      'Trip-Hop',  'Vocal',  'Jazz+Funk',  'Fusion',  'Trance',  
	      'Classical',  'Instrumental',  'Acid',  'House',  'Game',  
	      'Sound Clip',  'Gospel',  'Noise',  'AlternRock',  'Bass',  
	      'Soul',  'Punk',  'Space',  'Meditative',  
	      'Instrumental Pop',  'Instrumental Rock',  'Ethnic',  
	      'Gothic',  'Darkwave',  'Techno-Industrial',  'Electronic',  
	      'Pop-Folk',  'Eurodance',  'Dream',  'Southern Rock',  
	      'Comedy',  'Cult',  'Gangsta',  'Top 40',  'Christian Rap',  
	      'Pop/Funk',  'Jungle',  'Native American',  'Cabaret',  
	      'New Wave',  'Psychadelic',  'Rave',  'Showtunes',  
	      'Trailer',  'Lo-Fi',  'Tribal',  'Acid Punk',  
	      'Acid Jazz',  'Polka',  'Retro',  'Musical',  
	      'Rock & Roll',  'Hard Rock',  ]

winamp_genres = mp3_genres + \
		['Folk','Folk-Rock','National Folk','Swing','Fast Fusion','Bebob','Latin',
		'Revival','Celtic','Bluegrass','Avantgarde','Gothic Rock','Progressive Rock',
		'Psychedelic Rock','Symphonic Rock','Slow Rock','Big Band','Chorus',
		 'Easy Listening','Acoustic','Humour','Speech','Chanson','Opera',
		 'Chamber Music','Sonata','Symphony','Booty Bass','Primus','Porn Groove',
		 'Satire','Slow Jam','Club','Tango','Samba','Folklore','Ballad',
		 'Power Ballad','Rhythmic Soul','Freestyle','Duet','Punk Rock','Drum Solo',
		 'Acapella','Euro-House','Dance Hall']


t_bitrate = [
  [
    [0,32,48,56,64,80,96,112,128,144,160,176,192,224,256],
    [0,8,16,24,32,40,48,56,64,80,96,112,128,144,160],
    [0,8,16,24,32,40,48,56,64,80,96,112,128,144,160]
    ],
  [
    [0,32,64,96,128,160,192,224,256,288,320,352,384,416,448],
    [0,32,48,56,64,80,96,112,128,160,192,224,256,320,384],
    [0,32,40,48,56,64,80,96,112,128,160,192,224,256,320]
    ]
  ]
        
t_sampling_freq = [
  [22050, 24000, 16000],
  [44100, 48000, 32000]
  ]

frequency_tbl = {0:22050,1:24000,2:16000,3:44100,4:48000,5:32000,6:64000}


def getword(fp, off):
  fp.seek(off, 0)
  word = fp.read(4)
  return word

def get_l4 (s):
    return reduce (lambda a,b: ((a<<8) + b), map (long, map (ord, s)))

def get_xing_header (f):
    where = f.tell()
    try:
        f.seek(0)
        b = f.read(8192)
        i = string.find (b, 'Xing')
        if i > 0:
            # 32-bit fields; "Xing", flags, frames, bytes, 100 toc
            i = i + 4
            flags	= get_l4 (b[i:i+4]); i = i + 4
            frames	= get_l4 (b[i:i+4]); i = i + 4
            bytes	= get_l4 (b[i:i+4]); i = i + 4
            return flags, frames, bytes
        else:
            return None
    finally:
        f.seek (where)

MPG_MD_STEREO           = 0
MPG_MD_JOINT_STEREO     = 1
MPG_MD_DUAL_CHANNEL     = 2
MPG_MD_MONO             = 3

def get_newhead (word):
  word = get_l4 (word)
  if (word & (1<<20)):
    if (word & (1<<19)):
      lsf = 0
    else:
      lsf = 1
    mpeg25 = 0
  else:
    lsf = 1
    mpeg25 = 1
  lay = 4 - ((word>>17)&3)
  if mpeg25:
    sampling_frequency = 6 + ((word>>10) & 3)
  else:
    sampling_frequency = ((word>>10)&3) + (lsf * 3)
  error_protection 	= ((word>>16)&1) ^ 1
  bitrate_index 	= (word>>12) & 0xf
  padding 		= ((word >> 9) & 0x1)
  extension 		= ((word >> 8) & 0x1)
  mode	 		= ((word >> 6) & 0x3)
  mode_ext 		= ((word >> 4) & 0x3)
  copyright 		= ((word >> 3) & 0x1)
  original 		= ((word >> 2) & 0x1)
  emphasis 		= word & 0x3

  if mode == MPG_MD_MONO:
    stereo = 1
  else:
    stereo = 2


  return locals()
  import pprint
  pprint.pprint (locals())
  
def get_head(word):
  if len(word) != 4:
    return {}
  l = ord(word[0])<<24|ord(word[1])<<16|ord(word[2])<<8|ord(word[3])

  id = (l>>19) & 1
  layer = (l>>17) & 3
  protection_bit = (l>>16) & 1
  bitrate_index = (l>>12) & 15
  sampling_freq = (l>>10) & 3
  padding_bit = (l>>9) & 1
  private_bit = (l>>8) & 1
  mode = (l>>6) & 3
  mode_extension = (l>>4) & 3
  copyright = (l>>3) & 1
  original = (l>>2) & 1
  emphasis = (l>>0) & 1
  version_index = (l>>19) & 3
  bytes = l

##   for k,v in vars().items():
##     print k,v

  try:
    bitrate = t_bitrate[id][3-layer][bitrate_index]
  except IndexError:
    bitrate = 0

  try:
    fs = t_sampling_freq[id][sampling_freq]
  except IndexError:
    fs = 0

  return vars()

def is_mp3(h):
  #if h['bytes'] == -1: return 0
  if not (h['bitrate_index'] == 0 or \
	  h['version_index'] == 1 or \
	  ((h['bytes'] & 0xFFE00000) != 0xFFE00000) or \
	  (not h['fs']) or \
	  (not h['bitrate'])):
    return 1
  return 0

def get_v2head(fp):
  fp.seek(0,0)
  word = fp.read(3)
  if word != "ID3": return 0

  bytes = fp.read(2)
  major_version = ord(bytes[0])
  minor_version = ord(bytes[1])

  version = "ID3v2.%d.%d" % (major_version, minor_version)
  bytes = fp.read(1)
  unsync = (ord(bytes)>>7) & 1
  ext_header = (ord(bytes)>>6) & 1
  experimental = (ord(bytes)>>5) & 1

  bytes = fp.read(4)
  tagsize = 0

  for i in range(4):
    tagsize = tagsize + ord(bytes[3-i])*128*i

  if ext_header:
    ext_header_size = ext_header_size + 10
    bytes = fp.read(4)

  return vars()

def mp3info(fn):
  off = 0
  eof = 0
  h = 0
  i = 0
  tot = 4096

  if os.stat(fn)[6] == 0:
    return {}

  fp = open(fn)
  word = getword(fp, off)

  if off==0:
    id3v2 = get_v2head(fp)
    if id3v2:
      off = off + id3v2['tagsize']
      tot = tot + off
      word = getword(fp, off)

  nh = get_newhead (word)

  vbr = 0
  xh = get_xing_header (fp)
  if xh:
      flags, xing_frames, xing_bytes = xh
      if (flags & 0x08):
          vbr = 1
      #print 'xing: frames:%d bytes:%d' % (int(xing_frames), int(xing_bytes))

      if vbr:
        tpf = float([0,384,1152,1152][int(nh['lay'])])
        tpf = tpf / ([44100, 48000, 32000, 22050, 24000, 16000, 11025, 12000, 8000][int(nh['sampling_frequency'])] << nh['lsf'])
        print 'VBR average bit-rate:', int((xing_bytes * 8.) / (tpf * xing_frames * 1000))

  while 1:
    h = get_head(word)
    if not h: break
    off=off+1
    word = getword(fp, off)
    if off>tot: 
      print "BAD FILE", fn, os.stat(fn)[6]
      #os.unlink(fn)
      return {}
    if is_mp3(h): break


  fp.seek(0, 2)
  eof = fp.tell()

  try:
    fp.seek(-128, 2)
  except IOError, reason:
    return {}
  

  if h['id']:
    h['mean_frame_size'] = (144000. * h['bitrate']) / h['fs']
  else:
    h['mean_frame_size'] = (72000. * h['bitrate']) / h['fs']

  h['layer'] = h['mode']
  h['freq_idx'] = 3*h['id'] + h['sampling_freq']

  h['length'] = ((1.0*eof-off) / h['mean_frame_size']) * ((115200./2)*(1.+h['id']))/(1.0*h['fs'])
  h['secs'] = int(h['length'] / 100);
  

  i = {}
  i['VERSION'] = h['id']
  i['MM'] = int(h['secs']/60)
  i['SS'] = h['secs']%60
  i['STEREO'] = not(h['mode'] == 3)
  if h['layer'] >= 0:
    if h['layer'] == 3:
      i['LAYER'] = 2
    else:
      i['LAYER'] = 3
  else:
    i['LAYER'] = ''
  i['MODE'] = h['mode']
  i['COPYRIGHT'] = h['copyright']
  if h['bitrate'] >=0:
    i['BITRATE'] = h['bitrate']
  else:
    i['BITRATE'] = ''
  if h['freq_idx'] >= 0:
    i['FREQUENCY'] = frequency_tbl[h['freq_idx']]
  else:
    i['FREQUENCY'] = ''

  return i
			    
def get_mp3tag(fn):
  if os.stat(fn)[6] == 0:
    return {}

  try:
    fp = open(fn)
  except IOError, reason:
    return {}

  try:
    fp.seek(-128, 2)
  except IOError, reason:
    return {}

  line = None
  while 1:
    l = fp.readline()
    if not l: break
    line = l

  id = {}
  if line[:3] == 'TAG':
    v1 = 1
    i = 0; j = i + 3
    #id['d1'] = string.strip(line[i:j])
    i = j; j = i + 30
    id['TITLE'] = string.strip(line[i:j])
    i = j; j = i + 30
    id['ARTIST'] = string.strip(line[i:j])
    i = j; j = i + 30
    id['ALBUM'] = string.strip(line[i:j])
    i = j; j = i + 4
    id['YEAR'] = string.strip(line[i:j])
    i = j; j = i + 28
    id['COMMENT'] = string.strip(line[i:j])

    genre = ord(line[-1])
    try:
      id['GENRE'] = winamp_genres[ord(line[-1])]
    except IndexError:
      id['GENRE'] = "Unknown"


  return id

def Categorize(fn):
  i1 = mp3info(fn)
  i2 = get_mp3tag(fn)

  path1 = "cats/GENRE_ARIST/%s/%s" % (i2.get('GENRE', "Unknown"), i2.get('ARTIST', "Unknown"))
  path2 = "cats/GENRE/%s" % (i2.get('GENRE', "Unknown"), )
  path3 = "cats/ARIST/%s" % (i2.get('ARTIST', "Unknown"), )

  path1 = string.replace(path1, "\0", "_")
  path1 = string.replace(path1, " ", "_")
  path2 = string.replace(path2, "\0", "_")
  path2 = string.replace(path2, " ", "_")
  path3 = string.replace(path3, "\0", "_")
  path3 = string.replace(path3, " ", "_")

  if not os.path.isdir(path1):
    os.makedirs(path1)
  if not os.path.isdir(path2):
    os.makedirs(path2)
  if not os.path.isdir(path3):
    os.makedirs(path3)
  base, ffn = os.path.split(fn)

  try: os.symlink(fn, os.path.join(path1, ffn))
  except:  pass
  try: os.symlink(fn, os.path.join(path2, ffn))
  except:  pass
  try: os.symlink(fn, os.path.join(path3, ffn))
  except:  pass

def usage(progname):
  print __doc__ % vars()

def main(argv, stdout, environ):
  progname = argv[0]
  list, args = getopt.getopt(argv[1:], "", ["help", "cat"])

  if len(args) == 0:
    usage(progname)
    return
  for (field, val) in list:
    if field == "--help":
      usage(progname)
      return
    elif field == "--cat":
      for fn in args:
	Categorize(fn)
      return

  for fn in args:
    print fn
    i1 = mp3info(fn)
    for k,v in i1.items():
      print k,v

    i2 = get_mp3tag(fn)
    for k,v in i2.items():
      print k,v
    print


if __name__ == "__main__":
  main(sys.argv, sys.stdout, os.environ)
