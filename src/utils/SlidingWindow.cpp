template<typename _type, size_t _size>
size_t SlidingWindow<_type, _size>::getMCurrentInsertPosition() const {
    return mCurrentInsertPosition;
}

template<typename _type, size_t _size>
void SlidingWindow<_type, _size>::setMCurrentInsertPosition(size_t currentInsertPosition) {
    mCurrentInsertPosition = currentInsertPosition;
}

template<typename _type, size_t _size>
const array<_type, _size> &SlidingWindow<_type, _size>::getWindow() const {
    return mWindow;
}

template<typename _type, size_t _size>
void SlidingWindow<_type, _size>::setWindow(const array<_type, _size> &window) {
    mWindow = window;
}

template<typename _type, size_t _size>
const _type &SlidingWindow<_type, _size>::readAtIndex(const size_t &index) const {
    return mWindow[index % _size];
}

template<typename _type, size_t _size>
void SlidingWindow<_type, _size>::insert(const _type &newValue) {
    mWindow[mCurrentInsertPosition] = newValue;
    mCurrentInsertPosition = (mCurrentInsertPosition + 1) % _size;
}