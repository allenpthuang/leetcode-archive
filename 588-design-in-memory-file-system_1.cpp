class FileSystem {
 private:
  unsigned int inode_cnt;
  vector<pair<string, map<string, unsigned int> > > inodes;

  vector<string> tokenize(string path) {
    stringstream ss(path);
    string tmp = "";
    vector<string> result;
    while(getline(ss, tmp, '/')) {
      if (tmp == "") continue;
      result.push_back(tmp);
    }
    return result;
  }

  pair<bool, unsigned int>
  lookup_name(string name, unsigned int inode_no) {
    auto& [ignore, inode_list] = inodes[inode_no];
    if (inode_list.find(name) == inode_list.end()) {
      return {false, 0};
    }
    return {true, inode_list[name]};
  }

  unsigned int add_name_to_inode(string name, unsigned int inode_no) {
    auto& [ignore, inode_list] = inodes[inode_no];
    auto new_node_no = inode_cnt;
    inode_list[name] = new_node_no;
    inodes[new_node_no].first = "IS_DIR";
    inode_cnt++;

    return new_node_no;
  }

 public:
  FileSystem() {
    inodes.resize(301);
    inode_cnt = 1;
  }

  vector<string> ls(string path) {
    auto names = tokenize(path);
    auto cur_inode = 0u;
    for (const auto& name : names) {
      auto [is_exist, next_inode] = lookup_name(name, cur_inode);
      cur_inode = next_inode;
    }
    auto [dname, inode_list] = inodes[cur_inode];
    if (inode_list.empty() && dname != "IS_DIR") {
      if (path == "/") return {};
      return {names.back()};
    }
    vector<string> result;
    for (const auto& [fname, ignore] : inode_list) {
      result.push_back(fname);
    }
    return result;
  }
    
  void mkdir(string path) {
    auto names = tokenize(path);
    auto cur_inode = 0u;
    for (const auto& name : names) {
      auto [is_exist, next_inode] = lookup_name(name, cur_inode);
      if (is_exist) {
        cur_inode = next_inode;
        continue;
      }
      auto new_node = add_name_to_inode(name, cur_inode);
      cur_inode = new_node;
    }
  }
    
  void addContentToFile(string filePath, string content) {
    auto names = tokenize(filePath);
    auto cur_inode = 0u;
    for (const auto& name : names) {
      auto [is_exist, next_inode] = lookup_name(name, cur_inode);
      if (is_exist) {
        cur_inode = next_inode;
        continue;
      }
      auto new_node = add_name_to_inode(name, cur_inode);
      inodes[new_node].first = content;
      return;
    }
    inodes[cur_inode].first += content;
  }
    
  string readContentFromFile(string filePath) {
    auto names = tokenize(filePath);
    auto cur_inode = 0u;
    for (const auto& name : names) {
      auto [is_exist, next_inode] = lookup_name(name, cur_inode);
      if (is_exist) {
        cur_inode = next_inode;
        continue;
      }
    }
    return inodes[cur_inode].first;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

 /**
  * Idea: because only at most 300 calls will be made, there will
  * be at most 300 files or directories. We can create something
  * similar to inodes in Linux.
  *
  * inode: pair<string, map<string, unsigned int> >
  *        (content, fname -> inode_no)
  * inode list: vector<inode>
  *
  * Create a root inode first. inode_no = 0.
  * mkdir: /etc/defaults
  * Go to '/' first, see if its map already has 'etc', if so,
  * go on to that inode; if not, take an empty one from the inode list,
  * and add an entry to the map at '/'. In this case, (etc, 1).
  */

/* Runtime
15 ms
Beats
88.48%
Memory
19.8 MB
Beats
6.17%
*/

