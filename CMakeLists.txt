cmake_minimum_required(VERSION 3.8)

set(TARGET_NAME keepasscpp)

include_directories(src)

list(APPEND HEADERS
	src/base64.h
	src/binary.h
	src/cipher.h
	src/database.h
	src/entry.h
	src/exception.h
	src/format.h
	src/group.h
	src/icon.h
	src/io.h
	src/iterator.h
	src/kdb.h
	src/kdbx.h
	src/key.h
	src/metadata.h
	src/pugiconfig.h
	src/pugixml.h
	src/random.h
	src/security.h
	src/stream.h
	src/temporal.h
	src/util.h
)

list(APPEND SOURCES
	src/cipher.cpp
	src/entry.cpp
	src/group.cpp
	src/io.cpp
	src/kdb.cpp
	src/kdbx.cpp
	src/key.cpp
	src/metadata.cpp
	src/pugixml.cpp
	src/random.cpp
	src/stream.cpp
	src/util.cpp
)

add_library(${TARGET_NAME} ${HEADERS} ${SOURCES})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)

find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIR})
