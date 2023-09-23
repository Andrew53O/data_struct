istream& operator >>(istream& inputStream, Set& ASet)
{
    getline(inputStream, ASet.arr);

    cout << "arrnya " << ASet.arr;

    return inputStream;
}