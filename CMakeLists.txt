cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipZip)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PREBUILT_DIR ${PLUGIN_DIR}/prebuilts)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipZip.cpp
			${PLUGIN_DIR}/prebuilts/zip.c
			${PLUGIN_DIR}/prebuilts/unzip.c
			${PLUGIN_DIR}/prebuilts/ioapi_buf.c
			${PLUGIN_DIR}/prebuilts/ioapi_mem.c
			${PLUGIN_DIR}/prebuilts/ioapi.c
			${PLUGIN_DIR}/prebuilts/iowin32.c
			${PLUGIN_DIR}/prebuilts/aes/aescrypt.c
			${PLUGIN_DIR}/prebuilts/aes/aeskey.c
			${PLUGIN_DIR}/prebuilts/aes/aestab.c
			${PLUGIN_DIR}/prebuilts/aes/entropy.c
			${PLUGIN_DIR}/prebuilts/aes/fileenc.c
			${PLUGIN_DIR}/prebuilts/aes/hmac.c
			${PLUGIN_DIR}/prebuilts/aes/prng.c
			${PLUGIN_DIR}/prebuilts/aes/pwd2key.c
			${PLUGIN_DIR}/prebuilts/aes/sha1.c
			
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
			${PREBUILT_DIR}
			${PREBUILT_DIR}/aes
)


##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	list(APPEND PLUGIN_LINKDIRS
				${PREBUILT_DIR}/lib/win32
				${PREBUILT_DIR}/bin
	)
	
	#set(PLUGIN_LIBDIRS ${PREBUILT_DIR}/lib/win32)
	list(APPEND PLUGIN_LIBDIRS
				${PREBUILT_DIR}/lib/win32
	)
elseif(LINUX)
	#Linux libs here
elseif(APPLE)
	#Macos libs here
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
				z
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
endif(WIN32)