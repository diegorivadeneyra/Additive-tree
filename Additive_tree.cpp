#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <algorithm>

using namespace std;

struct Request {
    int Id;
    int Dedline;
    float Payment;
    int Cantidad;
    tuple<int,int> Origen;
    tuple<int,int> Destino;

    Request(int id, int dedline, int payment, tuple<int,int> origin, tuple<int,int> destino)
        : Id(id), Dedline(dedline), Payment(payment), Origen(origin), Destino(destino) {}

};

struct TreeNode {
    int Id;
    vector<int> Requests_ID;   
    vector<TreeNode> Children;
    int Profit = 0;        
    int MaxProfit = 0;     

    TreeNode(int id, vector<int> requests, int prof , int maxProf)
        : Id(id), Requests_ID(requests), Profit(prof), MaxProfit(maxProf) {}
};

struct AdditiveTree {
    shared_ptr<TreeNode> root;
    int maxCapacity;

    AdditiveTree(int capacity) : maxCapacity(capacity) {
        root = make_shared<TreeNode>(vector<int>{}); 
    }
};