extern bool signSuccessSearh;


struct Node {
	int data;
	Node* left;
	Node* right;
};

extern Node* RootABT;
extern Node* ParentVertexABT;

Node* addNodes(Node* pCurrent, int count);
void deleteABT(Node* pCurrent);
void printInverselySymmetrical(Node* pCurrent, int levelABT);
void printSymmetrical(Node* pCurrent, int levelABT);
void printForward(Node* pCurrent, int levelABT);

struct Stack {
	int levelABT;
	Node* passedVertex;
	Stack* next;
};

extern Stack* stack;

void initStack(Node* ABT);
void printNonRecursiveSymmetrical();

void searchNode(Node* pCurrent, int searchData);

Node* addNode(Node* pTemp, int newData);

void addNodeMenu();

void searchNodeMenu();
void printAllVision();
