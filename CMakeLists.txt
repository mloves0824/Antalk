CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(AntalkServer)

IF (WIN32)

ELSE (WIN32)

	ADD_SUBDIRECTORY(src/app/common/proto)
	ADD_SUBDIRECTORY(src/dep/tt_base)
	ADD_SUBDIRECTORY(src/app/login)
	ADD_SUBDIRECTORY(src/app/apigw)
	ADD_SUBDIRECTORY(src/app/auth)
	ADD_SUBDIRECTORY(src/app/data)
	ADD_SUBDIRECTORY(src/app/msg)

	IF (CMAKE_BUILD_TYPE MATCHES DEBUG)
		ADD_SUBDIRECTORY(tools/test/functest)
		ADD_SUBDIRECTORY(tools/test/tt_test)
	ENDIF (CMAKE_BUILD_TYPE MATCHES DEBUG)
ENDIF (WIN32)

