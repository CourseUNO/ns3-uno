set(source_files
        helper/uno-utils.cc
        helper/uno-results.cc
        helper/uno-node-statistics.cc
)

set(header_files
        helper/uno-utils.h
        helper/uno-results.h
        helper/uno-node-statistics.h
)


build_lib(
        LIBNAME uno-lab
        SOURCE_FILES ${source_files}
        HEADER_FILES ${header_files}
        LIBRARIES_TO_LINK
        ${libcore}
        ${libnetwork}
        ${libinternet}
        ${libpoint-to-point}
        ${libapplications}
        ${libtraffic-control}
        ${libmobility}
        TEST_SOURCES ""
)

add_library(uno-lab-python-extension python/person.c)