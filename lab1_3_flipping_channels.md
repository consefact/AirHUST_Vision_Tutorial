## lab1_3_flipping_channels

现在，给出一张部分区域被调换了通道顺序的彩色图像(processed_lena.jpg)，请你完成以下操作：

1. **读取图像**并分析其异常区域
2. **识别被调换的通道顺序**（如BGR变为RGB、BRG等）
3. **恢复异常区域的通道顺序**，使整张图像恢复正常显示
4. **验证恢复效果**并保存修复后的图像

### 你可能要用到的工具函数原型：

如果你是C++选手：

```cpp
// 读取图像
cv::Mat cv::imread(const cv::String &filename, int flags = 1);

// 提取图像中的特定区域（ROI）
cv::Mat::operator()(const cv::Rect &roi) const;

// 分离/合并通道
void cv::split(const cv::Mat &src, cv::Mat *mvbegin);
void cv::merge(const cv::Mat *mv, size_t count, cv::Mat &dst);

// 展示图像
void cv::imshow(const cv::String &winname, cv::InputArray mat);
int cv::waitKey(int delay = 0);

// 保存图像
bool cv::imwrite(const cv::String &filename, cv::InputArray img);
```

如果你是Python选手：

```python
# 读取图像
cv2.imread(filename: str, flags: int = ...) -> MatLike

# 提取图像中的特定区域（ROI）
# 使用切片操作：img[y1:y2, x1:x2]

# 分离/合并通道
cv2.split(img: MatLike) -> tuple[MatLike, ...]
cv2.merge(mv: Sequence[MatLike]) -> MatLike

# 展示图像
cv2.imshow(winname: str, mat: MatLike) -> None
cv2.waitKey(delay: int = ...) -> int

# 保存图像
cv2.imwrite(filename: str, img: MatLike, params: Sequence[int] = ...) -> bool
```

**提示**：你可以通过观察图像异常区域的颜色特征（如红色物体变为蓝色）来判断通道调换的具体方式，然后重新排列该区域的B、G、R通道顺序以恢复正常。



## 实验完毕后，记得提交修改（命令行中-m后的字符串可自行确定），以供检查：


```bash
git commit -a -m "my work on lab1_3 is done."
```


