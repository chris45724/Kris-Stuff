int binarySearch(vector<int> Values, int target){
    int location = -1;
    int attempts = 0;
    bool found = false;
    int first = 0;
    int last = Values.size();
    
    while(((found == false) && (attempts <= Values.size()) && (first <= last))){
        attempts++;
        int search = ((last - first) / 2 + first);
        if(target == Values[search]){
            found = true;
            location = search;
            break;
        } else if (target > Values[search]){
            first = search;
        } else if (target < Values[search]){
            last = search;
        }
        
    }

    cout << "Binary search used " << attempts << " attempts\nTotal list size is " << Values.size() << endl;

    return location;
}