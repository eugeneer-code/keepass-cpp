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

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_USE_STATIC_LIBS TRUE)

message("ZLIB LIB: ${ZLIB_LIBRARY}")
message("OPENSSL LIB: ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY}")

option(KEEPASS_BUILD_EXAMPLE OFF)

if(KEEPASS_BUILD_EXAMPLE)
	add_executable(test src/main.cpp)
	target_link_libraries(test ${TARGET_NAME})
endif()