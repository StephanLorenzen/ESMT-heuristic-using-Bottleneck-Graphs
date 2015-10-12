#include <vector>

#include "steiner/utils/point.hpp"
#include "steiner/utils/bottleneck_graph/bg_naive.hpp"

/*
 * Implementation of BottleneckGraphNaive constructor
 */
BottleneckGraphNaive::BottleneckGraphNaive(Graph &g) : BottleneckGraphSimple(g) {
  // Initial computation
  this->_recompute();
}

/*
 * Implementation of BottleneckGraphNaive destructor
 */
BottleneckGraphNaive::~BottleneckGraphNaive() { }

/*
 * Implementation of BottleneckGraphNaive::mergePoints(...)
 */
void BottleneckGraphNaive::mergePoints(const std::vector<unsigned int> &points) {
  BottleneckGraphSimple::mergePoints(points);
  // Do the recompute
  this->_recompute();
}

/*unsigned int BottleneckGraphNaive::_getEdgeIndex(const unsigned int i, const unsigned int j) {
  return BottleneckGraphSimple::_getEdgeIndex(i,j);
  }*/

/*
 * Implementation of BottleneckGraphNaive::_recompute()
 */
void BottleneckGraphNaive::_recompute() {
  // Calculate bottleneck tree
  for(unsigned int i=0; i<this->points.size(); i++)
    this->_traverse(i,i,0,0);
}
