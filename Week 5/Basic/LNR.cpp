stack<pair<Node* , int>> st;
        st.push({root , 1});

        while(!st.empty()){
            pair<Node* , int> t = st.top();
            Node* cur = st.top().first;
            int type = st.top().second;
            st.pop();

            if(cur == nullptr)
                continue;

            if(type == 1){
                st.push({cur , -1});
                st.push({cur -> right , 1});
                st.push({cur -> left , 1});
            }else{
                cout << cur -> data << " ";
            }
        }