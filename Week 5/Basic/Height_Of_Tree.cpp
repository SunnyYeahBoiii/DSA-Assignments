        if(root -> left == nullptr && root -> right == nullptr)
            return 1;

        int res = 1;
        if(root -> left)
            res = max(res , height(root -> left) + 1);
        if(root -> right)
            res = max(res , height(root -> right) + 1);

        return res;