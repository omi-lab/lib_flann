TARGET = lib_flann
TEMPLATE = lib

DEFINES += LIB_FLANN

SOURCES += src/flann.cpp
SOURCES += src/flann_cpp.cpp

HEADERS += inc/flann/config.h
HEADERS += inc/flann/defines.h
HEADERS += inc/flann/flann.h
HEADERS += inc/flann/flann.hpp
HEADERS += inc/flann/general.h

HEADERS += inc/flann/algorithms/all_indices.h
HEADERS += inc/flann/algorithms/autotuned_index.h
HEADERS += inc/flann/algorithms/center_chooser.h
HEADERS += inc/flann/algorithms/composite_index.h
HEADERS += inc/flann/algorithms/dist.h
HEADERS += inc/flann/algorithms/hierarchical_clustering_index.h
HEADERS += inc/flann/algorithms/kdtree_cuda_3d_index.cu
HEADERS += inc/flann/algorithms/kdtree_cuda_3d_index.h
HEADERS += inc/flann/algorithms/kdtree_cuda_builder.h
HEADERS += inc/flann/algorithms/kdtree_index.h
HEADERS += inc/flann/algorithms/kdtree_single_index.h
HEADERS += inc/flann/algorithms/kmeans_index.h
HEADERS += inc/flann/algorithms/linear_index.h
HEADERS += inc/flann/algorithms/lsh_index.h
HEADERS += inc/flann/algorithms/nn_index.h

HEADERS += inc/flann/io/hdf5.h

HEADERS += inc/flann/util/allocator.h
HEADERS += inc/flann/util/any.h
HEADERS += inc/flann/util/cutil_math.h
HEADERS += inc/flann/util/dynamic_bitset.h
HEADERS += inc/flann/util/heap.h
HEADERS += inc/flann/util/logger.h
HEADERS += inc/flann/util/lsh_table.h
HEADERS += inc/flann/util/matrix.h
HEADERS += inc/flann/util/object_factory.h
HEADERS += inc/flann/util/params.h
HEADERS += inc/flann/util/random.h
HEADERS += inc/flann/util/result_set.h
HEADERS += inc/flann/util/sampling.h
HEADERS += inc/flann/util/saving.h
HEADERS += inc/flann/util/serialization.h
HEADERS += inc/flann/util/timer.h

HEADERS += inc/flann/util/cuda/heap.h
HEADERS += inc/flann/util/cuda/result_set.h

HEADERS += inc/flann/nn/ground_truth.h
HEADERS += inc/flann/nn/index_testing.h
HEADERS += inc/flann/nn/simplex_downhill.h

