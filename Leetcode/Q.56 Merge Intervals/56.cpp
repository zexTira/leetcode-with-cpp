/*//
//  First if array size is equal to 1, just output it.
//  Next, we transform each two-num vector in araay intervals to a pair to sort them. 
// Then go throughout the array ,check if two pairs overlap, if so we take the right bound of whose right bound is bigger as the final right bound.
//  Otherwise we just need to jump to the next and output the result for now, and loop till the end.
//*/

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() == 1)
    {
        return intervals;
    }

    vector<pair<int, int>> p;
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        p.push_back({ intervals[i][0],intervals[i][1] });
    }
    sort(p.begin(), p.end());

    auto idx = p.begin();
    decltype(idx) temp;

    while (idx != p.end() - 1)
    {
        if ((*idx).second < (*(idx + 1)).first)
        {
            ans.push_back({ (*idx).first,(*idx).second });
            ++idx;
        }
        else if ((*idx).second <= (*(idx + 1)).second && (*idx).first >= (*(idx + 1)).first)
        {
            *idx = *(idx + 1);
            temp = idx + 1;
            p.erase(temp);
        }
        else
        {
            (*idx).second = max((*(idx + 1)).second, (*idx).second);
            temp = idx + 1;
            p.erase(temp);
        }
    }
    ans.push_back({ (*idx).first,(*idx).second });
    return ans;
}