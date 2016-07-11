#ifndef QUICKTCGASEGMENTER_H
#define QUICKTCGASEGMENTER_H

#include <math.h>
#include <set>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <iterator>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "TCGAUtilities.h"
#include "./NucleusSeg_Yi/ProcessTileUtils.h"

class QuickTCGASegmenter {
public:
    QuickTCGASegmenter();
    ~QuickTCGASegmenter();

    void SetSourceImage(const cv::Mat& imSrc);
    void SetLabImage(const cv::Mat& imLab);
    void SetROIImage(const cv::Mat& imROI);
    void SetPreSegmentation(const cv::Mat& imSeg);
    void DoSegmentation();
    void DoTemplateMatching();
    void DoNucleiSegmentationYi(float otsuRatio, double curvatureWeight, float sizeThld, float sizeUpperThld, double mpp, double kernelSize);
    void GetSegmentation(cv::Mat& imSeg);
    void RefineCurvature();
    void RefineShortCut();
    void OnTrackColorThreshold(int indColorTh);

private:
    void ComputeFeatureImage();


    cv::Mat m_imSrc;
    cv::Mat m_imLab;
    cv::Mat m_imROI;
    cv::Mat m_imSegPre;
    cv::Mat m_imSrcSample;
    cv::Mat m_imLabSample;
    cv::Mat m_imSegSample;
    cv::Mat m_imFeature;
    std::string m_WindowNameFull;
    std::string m_WindowNameROI;
    static const double m_SAMPLERATE;
    static const int m_COUNTOURAREA_MIN;
    static const int m_COLOR_SLIDER_MAX;
    static const int m_STRELE_SIZE;
    std::vector<std::vector<cv::Point> > m_contours;
    std::vector<cv::Vec4i> m_hierarchy;
};

#endif
