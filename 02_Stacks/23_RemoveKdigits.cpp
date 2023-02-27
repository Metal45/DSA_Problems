int count = 0, flag = 0;
        cout << nums << endl;

        while(count < k){
            for(int i = 0; i < nums.size(); i++){
                flag = 0;
                if(nums[i] > nums[i + 1]){
                    cout << nums[i] << endl;
                    nums.erase(i, 1);
                    flag = 1;
                    break;
                }
            }

            while(nums[0] == '0'){
                nums.erase(0, 1);
            }

            if(flag == 0){
                cout << "Here" << nums[nums.size() - 1] << endl;
                nums.erase(nums.size() - 1, 1);
            }

            cout << nums << endl;
            count++;
        }
        if(nums == ""){
            nums = "0";
        }
        return nums;