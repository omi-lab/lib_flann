/***********************************************************************
 * Software License Agreement (BSD License)
 *
 * Copyright 2008-2009  Marius Muja (mariusm@cs.ubc.ca). All rights reserved.
 * Copyright 2008-2009  David G. Lowe (lowe@cs.ubc.ca). All rights reserved.
 *
 * THE BSD LICENSE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *************************************************************************/

#ifndef FLANN_GROUND_TRUTH_H_
#define FLANN_GROUND_TRUTH_H_

#include "flann/algorithms/dist.h"
#include "flann/util/matrix.h"


namespace flann
{

template <typename Distance>
void find_nearest(const Matrix<typename Distance::ElementType>& dataset, typename Distance::ElementType* query, size_t* matches, size_t nn,
                  size_t skip = 0, Distance distance = Distance())
{
    //typedef typename Distance::ElementType ElementType;
    typedef typename Distance::ResultType DistanceType;
    size_t n = nn + skip;

    int* match = new int[n];
    DistanceType* dists = new DistanceType[n];

    dists[0] = distance(dataset[0], query, dataset.cols);
    match[0] = 0;
    int dcnt = 1;

    for (size_t i=1; i<dataset.rows; ++i) {
        DistanceType tmp = distance(dataset[i], query, dataset.cols);

        if (dcnt<n) {
            match[dcnt] = i;
            dists[dcnt++] = tmp;
        }
        else if (tmp < dists[dcnt-1]) {
            dists[dcnt-1] = tmp;
            match[dcnt-1] = i;
        }

        int j = dcnt-1;
        // bubble up
        while (j>=1 && dists[j]<dists[j-1]) {
            std::swap(dists[j],dists[j-1]);
            std::swap(match[j],match[j-1]);
            j--;
        }
    }

    for (size_t i=0; i<nn; ++i) {
        matches[i] = match[i+skip];
    }

    delete[] match;
    delete[] dists;
}


template <typename Distance>
void compute_ground_truth(const Matrix<typename Distance::ElementType>& dataset, const Matrix<typename Distance::ElementType>& testset, Matrix<size_t>& matches,
                          int skip=0, Distance d = Distance())
{
    for (size_t i=0; i<testset.rows; ++i) {
        find_nearest<Distance>(dataset, testset[i], matches[i], matches.cols, skip, d);
    }
}


}

#endif //FLANN_GROUND_TRUTH_H_
