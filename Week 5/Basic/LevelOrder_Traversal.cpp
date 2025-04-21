queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();

            cout << cur -> data << " ";

            if(cur -> left)
                q.push(cur -> left);
            if(cur -> right)
                q.push(cur -> right);
        }