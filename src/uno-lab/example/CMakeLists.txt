set(base_examples
        uno-example.cc
)
foreach(
        example
        ${base_examples}
)
    build_lib_example(
            NAME ${example}
            SOURCE_FILES ${example}
            LIBRARIES_TO_LINK
            ${libinternet}
            ${libmobility}
            ${libstats}
            ${libapplications}
            ${libuan}
    )
endforeach()