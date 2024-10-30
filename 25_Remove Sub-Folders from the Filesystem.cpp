// Question Link : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25

// Solution -> 

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Push all the folders into the SET;
        unordered_set<string> allFolders(folder.begin(), folder.end());
        vector<string> result;

        for (string currFolder : folder) {

            // currFolder = "/a/b"
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while (!currFolder.empty()) {
                size_t positionOfSlash = currFolder.find_last_of('/');

                // "/a/"
                currFolder = currFolder.substr(0,positionOfSlash);

                if(allFolders.find(currFolder)!=allFolders.end())
                {
                    isSubFolder = true;
                }
            }

            if(!isSubFolder)
            {
                result.push_back(tempFolder);
            }
        }

        return result;
    }
};