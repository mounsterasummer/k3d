INCLUDE_DIRECTORIES(${K3D_GIOMM_INCLUDE_DIRS})

LINK_DIRECTORIES(${GIOMM_LIBRARY_DIRS})

K3D_BUILD_MODULE(k3d-gio)
K3D_CREATE_MODULE_PROXY(k3d-gio)

TARGET_LINK_LIBRARIES(k3d-gio ${K3D_GIOMM_LIBS})

