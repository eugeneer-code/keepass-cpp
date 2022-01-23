cmake_minimum_required(VERSION 3.8)

set(TARGET_NAME keepasscpp)

include_directories(src)

list(APPEND HEADERS
	src/base64.hh
	src/binary.hh
	src/cipher.hh
	src/database.hh
	src/entry.hh
	src/exception.hh
	src/format.hh
	src/group.hh
	src/icon.hh
	src/io.hh
	src/iterator.hh
	src/kdb.hh
	src/kdbx.hh
	src/key.hh
	src/metadata.hh
	src/pugiconfig.hh
	src/pugixml.hh
	src/random.hh
	src/security.hh
	src/stream.hh
	src/temporal.hh
	src/util.hh
)

list(APPEND SOURCES
	src/cipher.cc
	src/entry.cc
	src/group.cc
	src/io.cc
	src/kdb.cc
	src/kdbx.cc
	src/key.cc
	src/metadata.cc
	src/pugixml.cc
	src/random.cc
	src/stream.cc
	src/util.cc
)

add_library(${TARGET_NAME} ${HEADERS} ${SOURCES})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} OpenSSL::SSL OpenSSL::Crypto)

