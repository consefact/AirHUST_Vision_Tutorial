## lab1_4_spin_around

现在，给出一张彩色图像，请你完成以下旋转操作：

1. **读取原始图像**并分析其尺寸与色彩模式
2. 绕图像中心**逆时针旋转30度**，将结果保存为pic1
3. **基于pic1，再绕图像中心顺时针旋转30度**，将结果保存为pic2
4. **比较并验证**pic2与原始图像的差异。如果想要完全消除这个差异，该怎么做？

### 你可能要用到的工具函数原型：

如果你是C++选手：

```cpp
// 读取图像
cv::Mat cv::imread(const cv::String &filename, int flags = 1);

// 获取旋转矩阵（center：旋转中心，angle：角度，scale：缩放比例）
cv::Mat cv::getRotationMatrix2D(cv::Point2f center, double angle, double scale);

// 应用仿射变换进行旋转
void cv::warpAffine(cv::InputArray src, cv::OutputArray dst,
                    cv::InputArray M, cv::Size dsize,
                    int flags = INTER_LINEAR,
                    int borderMode = BORDER_CONSTANT,
                    const cv::Scalar& borderValue = cv::Scalar());

// 获取图像中心点
cv::Point2f center = cv::Point2f(cols/2.0, rows/2.0);

// 保存图像
bool cv::imwrite(const cv::String &filename, cv::InputArray img);

// 展示图像
void cv::imshow(const cv::String &winname, cv::InputArray mat);
int cv::waitKey(int delay = 0);
```

如果你是Python选手：

```python
# 读取图像
cv2.imread(filename: str, flags: int = ...) -> MatLike

# 获取旋转矩阵（center：旋转中心，angle：角度，scale：缩放比例）
cv2.getRotationMatrix2D(center: tuple[float, float], angle: float, scale: float) -> MatLike

# 应用仿射变换进行旋转
cv2.warpAffine(src: MatLike, M: MatLike, dsize: tuple[int, int], flags: int = ..., ...) -> MatLike

# 获取图像尺寸（用于计算中心点）
height, width = img.shape[:2]
center = (width/2.0, height/2.0)

# 保存图像
cv2.imwrite(filename: str, img: MatLike, params: Sequence[int] = ...) -> bool

# 展示图像
cv2.imshow(winname: str, mat: MatLike) -> None
cv2.waitKey(delay: int = ...) -> int
```

**注意**：逆时针旋转时角度取正值，顺时针旋转时角度取负值。旋转时建议使用插值方法（如INTER_LINEAR）以保证图像质量。

## 实验完毕后，记得提交修改（命令行中-m后的字符串可自行确定），以供检查：

```bash
git commit -a -m "my work on lab1_4 is done."
```
