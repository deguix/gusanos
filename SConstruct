import re
import os
import sys

platform = sys.platform

# Manual user steps needed to build this (if not using package that will be provided to Arch Linux User Repository):
## Download Zoidcom 0.6.10 - NOTE: Download both of following files because a couple of files are corrupted:
### (Windows) https://web.archive.org/web/20160810041706if_/http://zoidcom.com/download/zoidcom-0.6.10.zip
### (Linux) https://web.archive.org/web/20140625032656if_/http://www.zoidcom.com/download/zoidcom-0.6.10.tar.gz
## Download Fmodex 4.44.64 from https://zdoom.org/files/fmod/ - TY ZDoom so much for this!
## Extract zoidcom to this folder (to solve its dependency).
## (Linux) Extract fmodex to this folder. (Windows) Install fmodex, and copy .dll to this folder and include folder files to "./fmodex/api/inc/"
## (Windows) Place other dll files at '.' folder. Good luck compiling them! Also run create_libs.sh in ./lib folder to make fixed .a files for FMODEx and zoidcom.

if (platform == "win64") or (platform == "win32") or (platform == "cygwin"):
	#use mingw only - msvc is not supported yet
	env = Environment(tools = ['mingw'], ENV = {'PATH' : os.environ['PATH']})
	
	env.Append(LIBS 				= ['fmodex', 'stdc++', 'lua51', 'zoidcom_vc', 'png', 'z', 'boost_filesystem-mt', 'allegro-4.4.2-md', 'ws2_32'])
	env.Append(LIBPATH 				= ['/bin', './lib', '.']) #will find dll's in program folder.
	env.Append(CPPDEFINES 			= ['WINDOWS', 'ALLEGRO_NO_FIX_ALIASES', 'ALLEGRO_LEGACY_NO_FIX_ALIASES'])
	env.Append(CPPFLAGS 			= ['-pipe', '-Wall', '-Wno-reorder']) #, '-Werror', '-static-libstdc++']
	env.Append(CXXFLAGS 			= ['-std=c++23'])
	env.Append(CPPPATH				= ['/include/allegro', './luajit-2.1/src/', './fmodex/api/inc/', './Utility','./zoidcom/include','./lua','./GUI','./Console','./OmfgScript','./http'])
#	env.Append(LINKFLAGS  			= ['-Wl,--no-demangle'])
#	env = Environment(tools = ['mingw'], ENV = {'PATH' : os.environ['PATH']})
#	
#	env.Append(LIBS 				= ['stdc++', 'lua51', 'zoidcom_vc', 'fmodex64', 'png', 'z', 'boost_filesystem-mt', 'alleg44'])
#	env.Append(LIBPATH 				= ['.', './luajit-2.1/src', './zoidcom/lib/msvc8_64/']) #will find dll's in program folder.
#	env.Append(CPPDEFINES 			= ['WINDOWS', 'ALLEGRO_NO_FIX_ALIASES', 'ALLEGRO_LEGACY_NO_FIX_ALIASES'])
#	env.Append(CPPFLAGS 			= ['-pipe', '-Wall', '-Wno-reorder']) #, '-Werror', '-static-libstdc++']
#	env.Append(CXXFLAGS 			= ['-std=c++23'])
#	env.Append(CPPPATH				= ['./allegro4/include', './luajit-2.1/src', './fmodex/api/inc/', './Utility','./zoidcom/include','./lua','./GUI','./Console','./OmfgScript','./http'])
else:
	#will probably use gcc here
	env = Environment()
	
	env.Append(LIBS 				= ['luajit-5.1', 'zoidcom', 'fmodex64', 'png', 'z', 'boost_filesystem', 'alleg'])
	env.Append(LIBPATH 				= ['/usr/lib', './zoidcom/lib/linux64/'])
	env.Append(CPPDEFINES 			= ['ALLEGRO_NO_FIX_ALIASES', 'ALLEGRO_LEGACY_NO_FIX_ALIASES'])
	env.Append(CPPFLAGS 			= ['-pipe', '-Wall', '-Wno-reorder']) #, '-Werror']
	env.Append(CXXFLAGS 			= ['-std=c++23'])
	env.Append(CPPPATH				= ['/usr/local/include/allegro', '/usr/include/luajit-2.1', '/usr/include/fmodex', './Utility','./zoidcom/include','./lua','./GUI','./Console','./OmfgScript','./http'])

debug = ARGUMENTS.get('debug', 0)
dedserv = ARGUMENTS.get('dedserv', 0)
progname = 'gusanos'
if int(debug):
	if int(dedserv):
		progname = 'gusanosd-ded'
		env.Append(CXXFLAGS = ['-Og', '-g'], CPPDEFINES=['DEBUG', 'DEDSERV', 'LOG_RUNTIME'])
	else:
		progname = 'gusanosd'
		env.Append(CXXFLAGS = ['-Og', '-g'], CPPDEFINES=['DEBUG', 'MAP_DOWNLOADING', 'LOG_RUNTIME'])
else:
	if int(dedserv):
		progname = 'gusanos-ded'
		env.Append(CXXFLAGS = ['-O3', '-g'], CPPDEFINES=['DEDSERV'])
	else:
		progname = 'gusanos'
		env.Append(CXXFLAGS = ['-O3', '-g'])

def find_files_gusanos(directory, pattern):
	sourcePattern = re.compile(pattern)
	srcs = []
	for root, dirs, files in os.walk(directory):
		exclude = set(['misc', 'zoidcom', 'fmodapi44464linux', 'fmodapi444linux', 'fmodex', 'luajit-2.1'])
		dirs[:] = [d for d in dirs if d not in exclude]
		for basename in files:
			if sourcePattern.search(basename):
				srcs.append(os.path.join(root, basename))
	return srcs

#TODO: Make configuration work - no luck so far (even though it's supposed to be simple -.-).
#conf = Configure(env)
#conf.CheckLib('boost_filesystem', language='C++')
#conf.CheckHeader('boost/utility.hpp', language='C++')
#conf.CheckLibWithHeader('zoidcom', 'zoidcom.h', 'C++')
#conf.CheckLibWithHeader('fmodex64-4.24.16', 'fmod.h', 'C++')
#conf.CheckLibWithHeader('png', 'png.h', 'C++')
#conf.CheckLibWithHeader('z', 'zlib.h', 'C++')
#env = conf.Finish()

# Weigh the impact carefully before adding other variables to this list.
import_env = [ 'TEMP', 'TMP' ]
for var in import_env:
    v = os.environ.get(var)
    if v:
        env['ENV'][var] = v

env.Program(progname, find_files_gusanos(".", '.*?\.(cpp|c)$'))