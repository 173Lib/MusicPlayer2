﻿#pragma once
#include "IPlayerCore.h"

// CMP3EncodeCfgDlg 对话框

class CMP3EncodeCfgDlg : public CDialog
{
	DECLARE_DYNAMIC(CMP3EncodeCfgDlg)

public:
	CMP3EncodeCfgDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMP3EncodeCfgDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MP3_ENCODE_CFG_DIALOG };
#endif

	MP3EncodePara m_encode_para;

	void InitBitrateCombobox(CComboBox& combo);
	void SetControlState();

	static void EncodeParaToCmdline(MP3EncodePara& para);

protected:
	//控制变量
	CButton m_cbr_radio;
	CButton m_abr_radio;
	CButton m_vbr_radio;
	CButton m_user_radio;
	CComboBox m_cbr_rate_combo;
	CComboBox m_abr_rate_combo;
	CSliderCtrl m_vbr_qua_sld;
	CEdit m_encode_cmdline_edit;
	CButton m_joint_stereo_btn;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCbrRateCombo();
	afx_msg void OnCbnSelchangeAbrRateCombo();
	afx_msg void OnBnClickedCbrRadio();
	afx_msg void OnBnClickedAbrRadio();
	afx_msg void OnBnClickedVbrRadio();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedUserRadio();
	virtual void OnOK();
	afx_msg void OnBnClickedJointStereoCheck();
};
