#ifndef FUNCTION_H
#define FUNCTION_H

/* an abstract class for the container used in this problem */
class ContainerBase {
	public:
		/* for the first-type operation */
		virtual int print() = 0;
		/* for the second-type operation */
		virtual void move(int) = 0;
		/* for the third-type operation */
		virtual void remove() = 0;
		int getSize() { return size; }

		virtual ~ContainerBase() {}
	protected:
		int size;	// the number of elements(people) in the container
};

/* array class deriving from ContainerBase */
class Array final : public ContainerBase {
	public:
		Array() {}
		Array(int n, int *arr) {
			size = n;
			
			mem = new int[size + 1];
			for(int i=1;i<=size;i++)	mem[i] = arr[i];
			cur = 1;
		}
		
		virtual int print() override { return mem[cur]; }
		/* TODO */
		virtual void move(int) override;
		/* TODO */
		virtual void remove() override;
		
		~Array() { delete[] mem; }
	private:
		int *mem;	// array for maintaining all the elements(the happy value of all the people)
		int cur;	// record who is carrying the ball
};

/* doubly linked list class deriving from ContainerBase */
class List final : public ContainerBase {
	public:
		List() {}
		List(int n, int *arr) {
			size = n;
			
			cur = new Node(arr[1]);
			Node *back = cur;
			for(int i=2;i<=n;i++) {
				Node *newNode = new Node(arr[i]);
				back->insertBack(newNode);
				back = newNode;
			}
		}
		
		virtual int print() override { return cur->getVal(); }
		/* TODO */
		virtual void move(int) override;
		/* TODO */
		virtual void remove() override;
		
		~List() { for(int i=1;i<=size;i++)	cur = cur->remove(); }
	private:
		/* nested class for the node in linked list */
		class Node {
			public:
				Node() {}
				Node(int newVal) : pre(nullptr), nxt(nullptr), val(newVal) {}
				/* insert a new node after the current node */
				void insertBack(Node *newNode) {
					nxt = newNode;
					newNode->pre = this; 
				}
				/* remove the current node and return the next node(or the previous node if the next node doesn't exist) */
				Node* remove() {
					Node *ret = (nxt == nullptr ? pre : nxt);
					if(pre != nullptr)	pre->nxt = nxt;
					if(nxt != nullptr)	nxt->pre = pre;
					delete this;
					return ret;
				}
				Node* getPre() { return pre; }
				Node* getNxt() { return nxt; }
				int getVal() { return val; }
			private:
				Node *pre, *nxt;
				int val;
		} *cur;	// record who is carrying the ball
};

/* a class for operation */
class Operation {
	public:
		int type,d;
};

/* TODO: create array/linked list based on operations and return it */
ContainerBase* create(int, int*, int, Operation*);

#endif
