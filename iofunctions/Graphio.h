//
// Created by Ricardo Nunes on 14/05/2020.
//

#ifndef CODE_GRAPHIO_H
#define CODE_GRAPHIO_H

#include "Graph.h"
#include "FileNotFound.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * This function reads the graph from the files inserted by the user.
 * @return Thw graph read
 */
Graph<int> readGraph();

/**
 * Function used to measure time
 * @param nodesFilename name of the file that contains the nodes
 * @param edgesFilename name of the file that contains the edges
 * @return The graph read
 */
Graph<int> readGraph(const string &nodesFilename, const string &edgesFilename);

/**
 * Auxiliary function used by readGraph() to read the edges provided in a file
 * @param edgesFilename name of the file that contains the edges
 * @param graph graph to insert the edges
 */
void getEdgesFromFile(const string &edgesFilename, Graph<int> &graph);

/**
 * Auxiliary function used by readGraph() to read the nodes provided in a file
 * @param nodesFilename name of the file that contains the nodes
 * @param graph graph to insert the nodes
 */
void getNodesFromFile(const string &nodesFilename, Graph<int> &graph);

#endif //CODE_GRAPHIO_H
