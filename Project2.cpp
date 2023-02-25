#include <iostream>
#include <fstream>
#include <sstream>
#include <Courses.h>
#include <vector>

using namespace std;

struct Node {
	Course course;
	Node* left;
	Node* right;
	Node() {
		left = nullptr;
		right = nullptr;
	}
	Node(Course newCourse) :
		node() {
		course = newCourse;
	}
};


// create course class
class Course {
private:
	Node* root;
	void destroyRecursive(Node* node);
	void addNode(Node* node, Course course);
	void InOrder(Node* node);
	void PostOrder(Node* node);
	void PreOrder(Node* node);
	Node* removeNode(Node* node, string courseID);
	string courseID;
	string courseName;
	vector<string> coursePreReq;
public:
	Course();
	virtual ~Courses();
	void InOrder();
	void PostOrder();
	void PreOrder();
	void Insert();
	void Remove(string courseID);
	Course Search(string courseID)
	Course(string& ID, string& name, vector<string> preReq);
	string getCourseID();
	string getCourseName();
	vector<string> getCoursePreReq();
	string courseToString();
}

// create constructors and getters
Course::Course(string& ID, strong& Name, vector<string> preReq) {
	this->courseID = ID;
	this->courseName = Name;
	this->coursePreReq = preReq;
}

string Course::getCourseID() {
	return this->courseID;
}

string Course::getCourseName() {
	return this->courseName;
}

vector<string> COurse::getCoursePreReq() {
	return this->coursePreReq;
}

string Course::courseToString() {
	return this->courseID + ", " + this->courseName;
}

//create display for courses
void displayCourses(Course course) {
	vector<string> coursePreReq = course.GetCoursePreReq();
	string preReq;
	if (courePreReq.size == 1) {
		preReq = course.getCoursePreReq()[0];
	}
	else if (coursePreReq.size > 1) {
		for (int i = 0; i < coursePreReq.size() - 1; i++) {
			preReq += coursePreReq[i] + ", ";
		}
		preReq += coursePreReq.back();
	}
	else {
		preReq = "n/a";
	}
	cout << course.GetCourseID() << ", " << course.getCourseName() << preReq << endl;
	cout << "Prerequisites: " << preReq << endl;
}

//load courses
void loadCourses(const string& inputFile, Courses*, coursesTree) {
	cout << "Loading input File " << inputFile << endl;
	ifstream file(inputFile);
	string currLine;
		while (getline(file, currLine)) {
			string ss(currLine);
			string word, id, name;
			vector <string> preReq;
			int i = 0;
			while (!ss.eof()) {
				getline(ss, word, ", ");
				if (i == 0) {
					id = word;
				}
				else if (i == 1) {
					name = word;
				}
				else {
					preReq.push_back(word);
				}
				i++;
			}
			Course course = Course(id, name, preReq);
			coursesTree->Insert(course);
		}


		file.close();
	}

// create tree to keep track and add courses easier

Course::Course() {
	root = nullptr;
}

Course::~Course() {
	destroyRecursive(root);
}

void Course::InOrder() {
	InOrder(root);
}

void Course::PostOrder() {
	postOrder(root);
}

void Course::Insert(Course course) {
	if (root == nullptr) {
		root = new Node(course)
	}
	else {
		this->addNode(root, course);
	}
}

void Course::Remove(string courseID) {
	this->removeNode(root, courseID);
}

//Search actions to find the course in the tree
Course Course::Search(string courseID) {
	Node* curr = root;
	while (curr != null ptr) {
		//if match is found return match
		if (curr->course.getCourseID().compare(courseID) == 0) {
			return curr->course;
		}
		// if the course number is smaller than the current node, go left
		else if (courseID.compare(curr->courseID.getCourseID()) < 0) {
			curr = curr->left;
		}
		// if the course number is bigger, go right
		else {
			curr = curr->right;
		}
		Course course;
		return course;
	}
}

//add the courses
void Course::addNode(Node* node, Course course) {
	if (node != nullptr && (node->course.getCourseID().compare(course.getCourseID() > 0)) {
		//if the node is smaller, go left
		if (node->left == nullptr) {
			node->left = new Node(course);
			return;
		}
		else {
			this->addNode(node->left, course);
		}
	}
	else if (node != nullptr && (node->course.getCourseID().compare(course.getCourseID()) < 0)) {
		if (node->right == nullptr) {
			node->right = newNode(course);
			return;
		}
		else {
			this->addNode(node->right, course);
		}
	}
}

void Course::destroyRecursive(Node* node) {
	if (node != nullptr) {
		destroyRecursive(node->left);
		destroyRecursive(node->right);
		delete node;
		node = nullptr;
	}
}


// print the courses in order
void Course::InOrder(Node* node) {
	if (node != nullptr) {
		InOrder(node->left);
		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl;
		InOrder(node->right);
	}
}

//print in post order
void Course::PostOrder(Node* node) {
	if (node != nullptr) {
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl;
	}
}

//print in preorder
void Course::PreOrder(Node* node) {
	if (node != nullptr) {
		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl;
		PreOrder(node->left);
		PreOrder(node->right)
	}
}

//delete a course
Node* Course::RemoveNode(Node* node, const string courseID) {
	if (node == nullptr) {
		return node;
	}
	else if (courseID.compare(node->course.getCourseID()) < 0) {
		node->left = removeNode(node->left, courseID);
	}
	else if (courseID.compare(node->course.getCourseID()) > 0) {
		node - right = removeNode(node->right, courseID);
	}
	else {
		//if it is a leaf
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		// if it is the left child
		else if (node->left != nullptr && node->right == nullptr) {
			node* temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
		}
		//if it is the right child
		else if (node->left == nullptr && node->right != nullptr) {
			Node* temp = node;
			node = node->right;
			delete temp;
			temp = nullptr;
		}
		//else delete both children
		else {
			Node* temp = node;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->course = temp->course;
			node->right = removeNode(node->right, temp->course.getCOurseID());
		}
	}
	return node;

}


int main() {
	Course* coursesTree;
	coursesTree = new Courses();
	Course course;
	string input, courseKey;


	//menu display
	cout << "Welcome to the course planner." << endl; << endl;
	int option = 0;
	while (option != 9) {
		cout << " 1.Load Data Structure" << endl;
		cout << " 2.Print Course List" << endl;
		cout << " 3.Print Course" << endl;
		cout << " 9.Exit" << endl;
		cout << "What would you like to do? ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Enter the path to the input File: ";
			cin >> input;
			loadCourses(input, coursesTree);
			break;
		case 2:
			cout << "Here is a simple schedule:" << endl; << endl;
			coursesTree->InOrder();
			break;
		case 3:
			cout << "What course do you want to know about? ";
			cin >> courseKey;
			course = coursesTree->Search(courseKey);

			if (!course.GetCourseID().empty()) {
				displayCourses(course);
			}
			else {
				cout << "Course Id " << courseKey << " not found." << endl;
			}
			break;
		case 9:
			cout << "Good Bye." << endl;
			break;
		default:
			cout << option << " is not a valid option";
			cin.clear();
		}
		cout << endl;
	}
	return 0;
}