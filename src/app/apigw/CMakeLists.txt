CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(APIGWSERVER)
SET(PROJECT_OUTNAME ApiGwServer)

IF (WIN32)
	IF (CMAKE_SIZEOF_VOID_P MATCHES 8)
		SET(OUTPUT_PATH_DEBUG ${PROJECT_SOURCE_DIR}/../../lib/debug_windows_x64)
		SET(OUTPUT_PATH_RELEASE ${PROJECT_SOURCE_DIR}/../../bin/windows_x64/im_common)	
		SET(PROJECT_LIB_DIR_DEBUG ${PROJECT_SOURCE_DIR}/../../lib/debug_windows_x64)
		SET(PROJECT_LIB_DIR_RELEASE ${PROJECT_SOURCE_DIR}/../../bin/windows_x64/im_common)		
	ELSEIF (CMAKE_SIZEOF_VOID_P MATCHES 4)
		SET(OUTPUT_PATH_DEBUG ${PROJECT_SOURCE_DIR}/../../lib/debug_windows_x86)
		SET(OUTPUT_PATH_RELEASE ${PROJECT_SOURCE_DIR}/../../bin/windows_x86/im_common)	
		SET(PROJECT_LIB_DIR_DEBUG ${PROJECT_SOURCE_DIR}/../../lib/debug_windows_x86)
		SET(PROJECT_LIB_DIR_RELEASE ${PROJECT_SOURCE_DIR}/../../bin/windows_x86/im_common)	
	ENDIF (CMAKE_SIZEOF_VOID_P MATCHES 8)
	
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH_DEBUG})
	SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH_RELEASE})
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH_DEBUG})
	SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH_RELEASE})
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_PATH_DEBUG})
	SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_PATH_RELEASE})
	
	SET(PROJECT_LIBS_PLATFORM_DEBUG
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_filesystem-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_system-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_thread-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_date_time-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_chrono-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_regex-vc140-mt-gd-1_56.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/boost_locale-vc140-mt-gd-1_56.lib

			debug ${PROJECT_LIB_DIR_DEBUG}/antutils.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/antdbio.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/antnetio.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/antdiskio.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/libcurld.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/libeay32.lib
			debug ${PROJECT_LIB_DIR_DEBUG}/ssleay32.lib
		)
		
	SET(PROJECT_LIBS_PLATFORM_RELEASE
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_filesystem-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_system-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_thread-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_date_time-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_chrono-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_regex-vc140-mt-1_56.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/boost_locale-vc140-mt-1_56.lib
			
			optimized ${PROJECT_LIB_DIR_RELEASE}/antutils.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/antdbio.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/antnetio.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/antdiskio.lib		
			optimized ${PROJECT_LIB_DIR_RELEASE}/libcurl.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/libeay32.lib
			optimized ${PROJECT_LIB_DIR_RELEASE}/ssleay32.lib				
		)
	
	SET(PROJECT_SRCS
	   src/AntNetIO4/tcp_server.cpp
	   src/AntNetIO4/antnetio.cpp
	   src/AntNetIO4/tcp_connection.cpp
	   src/AntNetIO4/udp_dispatch.cpp
	   src/AntNetIO4/parse_request_data.cpp
	   src/AntNetIO4/bundle_response_data.cpp
	   src/AntNetIO4/connections.cpp
	   src/AntNetIO4/sessions.cpp
	   src/AntNetIO4/session_manager.cpp  
	   src/AntNetIO4/ccryp.cpp    
	   src/AntNetIO4/endpoint_manager.cpp
	   src/AntNetIO4/http_request.cpp

	   src/main.cpp
	   src/handler_common.cpp
	   src/handler_common4.cpp
	   src/handler_manager.cpp
	   src/server_impl_win.cpp
	   src/server.cpp
	   src/serverinfo_manager.cpp
	   src/user_data_cache_mgr.cpp
	   src/connection_mgr.cpp
	   src/commfunc.cpp
	   src/api_xml_parser.cpp
	   src/db_manager.cpp
	   src/sysdatamgr.cpp
	   src/syssaasitem.cpp
	   src/sysserveritem.cpp
	   src/sysadminitem.cpp
	   
	)

	FILE(GLOB PROJECT_HDRS  ${PROJECT_SOURCE_DIR}/inc/*.h ${PROJECT_SOURCE_DIR}/inc/*.hpp)
	SOURCE_GROUP("Include" FILES ${PROJECT_HDRS}) 
	
	FILE(GLOB_RECURSE PROJECT_HDRS_HANDLER  ${PROJECT_SOURCE_DIR}/inc/handle/*.h ${PROJECT_SOURCE_DIR}/inc/handle/*.hpp)
	SOURCE_GROUP("Include\\Handler" FILES ${PROJECT_HDRS_HANDLER}) 

	FILE(GLOB WINSERVICE_SRCS  ${PROJECT_SOURCE_DIR}/../UpCommon/WinService/*.cpp)

	INCLUDE_DIRECTORIES(
		${PROJECT_SOURCE_DIR}/../../inc/AntThirdParty
		${PROJECT_SOURCE_DIR}/../../inc
		${PROJECT_SOURCE_DIR}/inc
		${PROJECT_SOURCE_DIR}/../UpCommon
	)

	ADD_EXECUTABLE(${PROJECT_OUTNAME} ${PROJECT_SRCS} ${PROJECT_HDRS} ${PROJECT_HDRS_HANDLER} ${WINSERVICE_SRCS})
	TARGET_LINK_LIBRARIES(${PROJECT_OUTNAME} ${PROJECT_LIBS_PLATFORM_RELEASE} ${PROJECT_LIBS_PLATFORM_DEBUG})	
	SET_TARGET_PROPERTIES(${PROJECT_OUTNAME} PROPERTIES LINK_FLAGS /MAP)

	ADD_DEPENDENCIES(${PROJECT_OUTNAME} antdbio antnetio antdiskio antutils)
ELSE(WIN32)
	SET(CMAKE_C_COMPILER g++)
	SET(CMAKE_CXX_COMPILER g++)

	IF (NOT CMAKE_BUILD_TYPE)
		SET(CMAKE_BUILD_TYPE RELEASE)
	ENDIF (NOT CMAKE_BUILD_TYPE)

	IF (NOT PLATFORM)
		SET(PLATFORM X64)
	ENDIF (NOT PLATFORM)



	IF (PLATFORM MATCHES MIPS)
		IF (CMAKE_SIZEOF_VOID_P MATCHES 8)
			if (CMAKE_BUILD_TYPE MATCHES DEBUG)
				ADD_DEFINITIONS(-DDEBUG)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -fshort-wchar -fPIC")
				SET(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x64)
				SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x64)
				SET(PROJECT_LIBS_PLATFORM
					libboost_system-gcc48-mt-d-1_56.so
					libboost_thread-gcc48-mt-d-1_56.so
					libboost_filesystem-gcc48-mt-d-1_56.so
					
					pthread
					dl
					z
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: debug_linux_x64")

			ELSEIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
				ADD_DEFINITIONS(-DRELEASE)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -fshort-wchar -fopenmp -fPIC")
				SET(PROJECT_LIB_DIR
					${PROJECT_SOURCE_DIR}/../../lib/release_linux_x64
					${PROJECT_SOURCE_DIR}/../../bin/linux_x64/im_common
				)
				SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/linux_x64/im_common)
				SET(PROJECT_LIBS_PLATFORM
					libboost_system-gcc48-mt-1_56.so
					libboost_thread-gcc48-mt-1_56.so
					libboost_filesystem-gcc48-mt-1_56.so
					
					pthread
					dl
					z
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: release_linux_x64")

			ENDIF (CMAKE_BUILD_TYPE MATCHES DEBUG)
		ELSEIF (CMAKE_SIZEOF_VOID_P MATCHES 4)
			if (CMAKE_BUILD_TYPE MATCHES DEBUG)
				ADD_DEFINITIONS(-DDEBUG)
				SET(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x86)
				SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x86)
				SET(PROJECT_LIBS_PLATFORM
					libboost_system-gcc48-mt-d-1_56.so
					libboost_thread-gcc48-mt-d-1_56.so
					libboost_filesystem-gcc48-mt-d-1_56.so

					pthread
					dl
					z
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: debug_linux_x86")

		#mips平台32位Release版本
			ELSEIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: release_linux_mips32")
				ADD_DEFINITIONS(-DRELEASE)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -g -fshort-wchar -fopenmp -fPIC")
				SET(PROJECT_LIB_DIR
					${PROJECT_SOURCE_DIR}/../../bin/linux_mips32/im_common
				)
				SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/linux_mips32/upapiserver)
				SET(PROJECT_LIBS_PLATFORM
					#libboost_system-gcc48-mt-1_56.so
					#libboost_thread-gcc48-mt-1_56.so
					#libboost_filesystem-gcc48-mt-1_56.so
					libboost_system.so
			libboost_filesystem.so
			libboost_thread.so         
			libantplugin.so
					libantnetio.so
					libantdbio.so
					libantdiskio.so
					libantutils.so
					libcurl.so
					libcrypto.so
					libssl.so

							

					pthread
					dl
					z
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: release_linux_mips32")

			ENDIF (CMAKE_BUILD_TYPE MATCHES DEBUG)
		ENDIF (CMAKE_SIZEOF_VOID_P MATCHES 8)
	ELSE(PLATFORM MATCHES MIPS)
		IF (CMAKE_SIZEOF_VOID_P MATCHES 8)
			if (CMAKE_BUILD_TYPE MATCHES DEBUG)
				ADD_DEFINITIONS(-DDEBUG)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -fshort-wchar")
				SET(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x64)
				SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x64)
				SET(PROJECT_LIBS_PLATFORM
					libantnetio.so
					libantdbio.so
					libantdiskio.so
					libantutils.so
					
					libcurl.so
					libssl.so
					libcrypto.so
					
					libboost_system-gcc48-mt-d-1_56.so
					libboost_thread-gcc48-mt-d-1_56.so
					libboost_filesystem-gcc48-mt-d-1_56.so

					pthread
					dl
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: debug_linux_x64")

			ELSEIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
				ADD_DEFINITIONS(-DRELEASE)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -fshort-wchar -fopenmp")
				SET(PROJECT_LIB_DIR
					${PROJECT_SOURCE_DIR}/../../lib/release_linux_x64
					${PROJECT_SOURCE_DIR}/../../bin/linux_x64/im_common
				)
				SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/linux_x64/upapiserver)
				SET(PROJECT_LIBS_PLATFORM
					libantnetio.so
					libantdbio.so
					libantdiskio.so
					libantutils.so
					
					libcurl.so
					libssl.so
					libcrypto.so
					
					libboost_system-gcc48-mt-1_56.so
					libboost_thread-gcc48-mt-1_56.so
					libboost_filesystem-gcc48-mt-1_56.so

					pthread
					dl
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: release_linux_x64")

			ENDIF (CMAKE_BUILD_TYPE MATCHES DEBUG)
		ELSEIF (CMAKE_SIZEOF_VOID_P MATCHES 4)
			if (CMAKE_BUILD_TYPE MATCHES DEBUG)
				ADD_DEFINITIONS(-DDEBUG)
				SET(PROJECT_LIB_DIR ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x86)
				SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../lib/debug_linux_x86)
				SET(PROJECT_LIBS_PLATFORM
					pthread
					dl
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: debug_linux_x86")

			ELSEIF (CMAKE_BUILD_TYPE MATCHES RELEASE)
				ADD_DEFINITIONS(-DRELEASE)
				SET(PROJECT_LIB_DIR
					${PROJECT_SOURCE_DIR}/../../lib/release_linux_x86
					${PROJECT_SOURCE_DIR}/../../bin/linux_x86
				)
				SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/linux_x86)
				SET(PROJECT_LIBS_PLATFORM
					pthread
					dl
				)
				MESSAGE(STATUS "${PROJECT_OUTNAME} is VERSION: release_linux_x86")

			ENDIF (CMAKE_BUILD_TYPE MATCHES DEBUG)
		ENDIF (CMAKE_SIZEOF_VOID_P MATCHES 8)

	ENDIF (PLATFORM MATCHES MIPS)


	SET(PROJECT_SRCS
	   src/AntNetIO4/tcp_server.cpp
	   src/AntNetIO4/antnetio.cpp
	   src/AntNetIO4/tcp_connection.cpp
	   src/AntNetIO4/udp_dispatch.cpp
	   src/AntNetIO4/parse_request_data.cpp
	   src/AntNetIO4/bundle_response_data.cpp
	   src/AntNetIO4/connections.cpp
	   src/AntNetIO4/sessions.cpp
	   src/AntNetIO4/session_manager.cpp  
	   src/AntNetIO4/ccryp.cpp    
	   src/AntNetIO4/endpoint_manager.cpp
	   src/AntNetIO4/http_request.cpp
	   src/AntNetIO4/local_network_info.cpp

	   src/main.cpp
	   src/handler_common.cpp
	   src/handler_common4.cpp
	   src/handler_manager.cpp
	   src/server_impl.cpp
	   src/server.cpp
	   src/serverinfo_manager.cpp
	   src/user_data_cache_mgr.cpp
	   src/connection_mgr.cpp
	   src/commfunc.cpp
	   src/api_xml_parser.cpp
	   src/db_manager.cpp
	   src/sysdatamgr.cpp
	   src/syssaasitem.cpp
	   src/sysserveritem.cpp
	   src/sysadminitem.cpp
	   
	)

	SET(PROJECT_HDRS

	)

	INCLUDE_DIRECTORIES(
		${PROJECT_SOURCE_DIR}/../../inc/AntThirdParty
		${PROJECT_SOURCE_DIR}/../../inc
		${PROJECT_SOURCE_DIR}/inc
		${PROJECT_SOURCE_DIR}/../UpCommon
	)

	LINK_DIRECTORIES(${PROJECT_LIB_DIR})

	ADD_EXECUTABLE(${PROJECT_OUTNAME} ${PROJECT_SRCS} ${PROJECT_HDRS})
	TARGET_LINK_LIBRARIES(${PROJECT_OUTNAME} ${PROJECT_LIBS_PLATFORM})
	ADD_DEPENDENCIES(${PROJECT_OUTNAME} antdbio antnetio antdiskio antutils)
ENDIF (WIN32)

MESSAGE(STATUS "${PROJECT_OUTNAME} is BINARY dir:" ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "${PROJECT_OUTNAME} is SOURCE dir:" ${PROJECT_SOURCE_DIR})
