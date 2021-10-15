# Get plugin interface includes
# [out] output_path : Contains information for building the AutoBatchTools plugin.
function(get_plugin_interface output_path)

    include(FetchContent)
    string(TOLOWER "AutoBatchTools" repo)

    FetchContent_Declare(
      AutoBatchTools
      GIT_REPOSITORY https://github.com/karakirimu/AutoBatchTools.git
      GIT_TAG        main
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    FetchContent_MakeAvailable(${repo})

    FetchContent_GetProperties(${repo})
    if(NOT ${repo}_POPULATED)
      FetchContent_Populate(${repo})
      add_subdirectory(${${repo}_SOURCE_DIR} ${${repo}_BINARY_DIR})
    endif()

    set(PLUGIN_INTERFACE_DIRECTORY
        ${${repo}_SOURCE_DIR}/src/plugininterface
    )

    set(PLUGIN_FILES
        InnerFunctions.h
        extraplugininterface.h
        pluginvariants.h
        pluginwidget.h
    )

    foreach(extfile IN LISTS PLUGIN_FILES)
        configure_file(
            ${PLUGIN_INTERFACE_DIRECTORY}/${extfile}
            ${CMAKE_CURRENT_BINARY_DIR}/${extfile}
            COPYONLY
        )
    list(APPEND PLUGIN_OUT_FILES ${CMAKE_CURRENT_BINARY_DIR}/${extfile})
    endforeach()

    set(${output_path} ${PLUGIN_OUT_FILES} PARENT_SCOPE)

endfunction()
