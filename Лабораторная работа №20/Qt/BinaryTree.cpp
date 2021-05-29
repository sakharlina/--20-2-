#include "binarytree.h"
#include <QFile>
#include <QTextStream>
#include <QtCore/qmath.h>
#include <QFont>
QFile inputFile("D:/Qt/BinaryTree/elements.txt");
QTextStream stream(&inputFile);
QString line;
int x, y; 
int shift = 250; 
double R = 0;
double node_x = 0, node_y = 0; 
double text_x = 0, text_y = 0;
int tree_height = 0;
int* array_for_counting_indexes;
double x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
int coefficient;
double window_height = 0, window_width = 0;
bool isCurrentNodeLeft; 
NodeShape *nodeshape;
BinaryTree::BinaryTree()
{
    root = nullptr;
}
BinaryTree::~BinaryTree(){
    delete_tree(root);
}
void BinaryTree::delete_tree(Node *leaf){
    if (leaf != nullptr) {
        delete_tree(leaf->left);
        delete_tree(leaf->right);
        delete leaf;
    }
}
void BinaryTree::get_subtrees_sizes(const int size, int &left_size, int &right_size){
    if ((size - 1) % 2 == 0) {
        left_size = (size - 1) / 2;
        right_size = left_size;
    }
    else {
        left_size = size / 2;
        right_size = (size - 1) / 2;
    }
}
void BinaryTree::create_balanced_binary_tree(Node *&leaf, int size){
    if (size == 0) {
        leaf = nullptr;
        return;
    }
    if (line == "")
        return;
    leaf = new Node;
    leaf->data = line.toDouble();
    leaf->left = nullptr;
    leaf->right = nullptr;
    line = stream.readLine();
    int left_subtree_size, right_subtree_size;
    get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
    create_balanced_binary_tree(leaf->left, left_subtree_size);
    create_balanced_binary_tree(leaf->right, right_subtree_size);
}
int BinaryTree::depth_tree(Node *leaf){
    if (leaf == nullptr)
        return 0;
    return qMax(depth_tree(leaf->right), depth_tree(leaf->left)) + 1;
}
void BinaryTree::print_tree(Node *&leaf, QGraphicsScene *scene){
    if (leaf == nullptr) {
        array_for_counting_indexes[y] = array_for_counting_indexes[y] + 1;
        return;
    }
    y++;
    array_for_counting_indexes[y-1] = array_for_counting_indexes[y-1] + 1;
    x = array_for_counting_indexes[y - 1];
    R = (window_width - shift)/(qPow(2, tree_height));
    nodeshape = new NodeShape;
    node_x = window_width*(2*x-1)/qPow(2, y);
    node_y = window_height*(qSqrt(y*y*(y*1.315)))/qPow(2, tree_height);
    if (y == 1){
        x_1 = node_x;
        y_1 = node_y;
    }
    else{
        x_2 = node_x;
        y_2 = node_y;
        double D = qSqrt(qPow(x_2 - x_1, 2) + qPow(y_2 - y_1, 2));
        double d = D - R; 
        double big_triangle_cathetus = qSqrt(qPow(x_2 - x_1, 2));
        double small_triangle_cathetus = big_triangle_cathetus * d / D; 
        if (isCurrentNodeLeft)
            coefficient = 1;
        else
            coefficient = -1;
        double new_x_1 = x_2 + coefficient * small_triangle_cathetus;
        double new_y_1 = y_2 - qSqrt(d * d - qPow(small_triangle_cathetus, 2));
        x_1 = new_x_1;
        y_1 = new_y_1;
        QGraphicsItem *edge = scene->addLine(x_1, y_1, x_2, y_2, QPen(Qt::black));
        scene->addItem(edge);
        x_1 = x_2;
        y_1 = y_2;
    }
    nodeshape->SetNodeCoords(node_x, node_y);
    line = QString::number(leaf->data);
    text_x = node_x-R/6*line.length();
    text_y = node_y - 3*R/8;
    nodeshape->SetNodeRadius(R);
    scene->addItem(nodeshape);
    nodeshape->setPos(0, 0);
    QFont font("Times", R/3);
    QGraphicsTextItem *text = scene->addText(QString::number(leaf->data), font);
    text->setPos(text_x, text_y);
    isCurrentNodeLeft = true;
    print_tree(leaf->left, scene);
    isCurrentNodeLeft = false;
    x_1 = window_width*(2*array_for_counting_indexes[y - 1]-1)/qPow(2, y);
    y_1 = window_height*(qSqrt(y*y*(y*1.315)))/qPow(2, tree_height);
    print_tree(leaf->right, scene);
    y--;
    if (y == 1) {
        x = 1;
        x_1 = window_width*(2*x-1)/qPow(2, y);
        y_1 = window_height*(qSqrt(y*y*(y*1.315)))/qPow(2, tree_height);
    }
}
void BinaryTree::create_balanced_binary_tree(int size){
    inputFile.open(QFile::ReadOnly | QFile::Text);
    line = stream.readLine();
    root = new Node;
    root->data = line.toDouble();
    root->left = nullptr;
    root->right = nullptr;
    line = stream.readLine();
    if ((size - 1) > 0) {
        int left_subtree_size, right_subtree_size;
        get_subtrees_sizes(size, left_subtree_size, right_subtree_size);
        create_balanced_binary_tree(root->left, left_subtree_size);
        create_balanced_binary_tree(root->right, right_subtree_size);
    }
    inputFile.flush();
    inputFile.close();
}
int BinaryTree::depth_tree(){
    return depth_tree(root);
}
void BinaryTree::print_tree(QGraphicsScene *scene){
    x = 0;
    y = 0;
    tree_height = depth_tree(root);
    window_width = scene->width();
    window_height = scene->height();
    array_for_counting_indexes = new int[tree_height+1];
    for (int i = 0; i < tree_height; i++)
        array_for_counting_indexes[i] = 0;
    print_tree(root, scene);
    delete[] array_for_counting_indexes;
}
