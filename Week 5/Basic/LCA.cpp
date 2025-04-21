if(v1 > v2)
            swap(v1 , v2);
        
        if(v1 <= root -> data && root -> data <= v2)
            return root;
        else if(root -> data < v1)
            return lca(root -> right , v1 , v2);
        else return lca(root -> left , v1 , v2);