// PROBLEM :- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// LEETCODE | HARD | DESIGN , BINARY TREE

// Solution :- 

// We first serialize the binary tree in preorder fashion.
// Stored the NULL as "1009" custom value.
// And then we retrive the nodes from the string, and using the preorder fashion again, we built the tree.

vector<int> nums;
string input = "";
int pointer = -1;

TreeNode* recurse(){
    pointer++;
    
    if(nums[pointer] == 1009 || pointer == nums.size())
        return NULL;
    
    TreeNode* node = new TreeNode(nums[pointer]);
    node->left = recurse();
    node->right = recurse();
    return node;
}

void recursePreorder(TreeNode* node){
    if(node == NULL){
        input += "1009;";
        return;
    }
    string cur = to_string(node->val);
    input += cur;
    input += ';';
    recursePreorder(node->left);
    recursePreorder(node->right);
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        input = "";
        // used Preorder to store the tree in the array. Marked NULL as value 1009.
        recursePreorder(root);
        return input;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length() == 0)
            return NULL;
        
        // traversed the string, stored it in an integer array (can be avoided as optimization of space)
        // then traverse this array to get the tree back, also done in pre-order fashion.
        
        nums.clear();
        
        string word = "";
        
        pointer = -1;
        
        for(int i = 0 ; i < data.length(); i++){
            if(data[i] == ';'){
                int current = stoi(word);
                nums.push_back(current);
                word = "";
            }else{
                word.push_back(data[i]);
            }
        }
        TreeNode* root = recurse();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;