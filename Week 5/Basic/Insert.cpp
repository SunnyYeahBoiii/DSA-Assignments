Node* cur = root;

        if(root == nullptr)
            return new Node(data);

        while(1){
            if(cur == nullptr){
                cur = new Node(data);
                return root;
            }
            if(data < cur -> data){
                if(cur -> left == nullptr){
                    cur -> left = new Node(data);
                    return root;
                }
                cur = cur -> left;
            }else{
                if(cur -> right == nullptr){
                    cur -> right = new Node(data);
                    return root;
                }
                cur = cur -> right;
            }
        }
        
        return root;