
if( MB_WITH_EXAMPLES )

  include_directories(
    ${PROJECT_BINARY_DIR}/include
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/shaderFiles.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/shaderFiles.h )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/assetsFiles.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/assetsFiles.h )


  #set( MBALIENTEXTURE_HEADERS )
  #set( MBALIENTEXTURE_SOURCES alienTexture.cpp )
  #set( MBALIENTEXTURE_LINK_LIBRARIES
  #  mb
  #)
  #common_application( mbAlienTexture )


  set( MBALPHATEXTURES_HEADERS )
  set( MBALPHATEXTURES_SOURCES alphaTextures.cpp )
  set( MBALPHATEXTURES_LINK_LIBRARIES
    mb
  )
  common_application( mbAlphaTextures )


  set( MBMORECUBES_HEADERS )
  set( MBMORECUBES_SOURCES moreCubes.cpp )
  set( MBMORECUBES_LINK_LIBRARIES
    mb
  )
  common_application( mbMoreCubes )

endif( )
