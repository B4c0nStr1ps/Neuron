macro(GetFilesWithSourceGroups GLOB_TYPE VARIABLE RELATIVE_TO)
	set(SEARCH_REGEX "${RELATIVE_TO}/*")
    file(${GLOB_TYPE} files ${SEARCH_REGEX})
    foreach(file ${files})
        file(RELATIVE_PATH relFile ${RELATIVE_TO} ${file})
        get_filename_component(folder ${relFile} PATH)
        string(REPLACE / \\ folder "${folder}")
        source_group("${folder}" FILES ${file})
    endforeach()
    list(APPEND ${VARIABLE} ${files})
endmacro()
 


  