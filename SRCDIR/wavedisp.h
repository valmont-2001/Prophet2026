#ifndef __WAVEDISPH__
#define __WAVEDISPH__


class WaveDisp : public wxScrolledWindow
{
public:
   typedef enum { WAVEDISP_NOHIGHLIGHT, WAVEDISP_SAMPLERANGE, WAVEDISP_SUSTAINLOOP, WAVEDISP_RELEASELOOP } hightlighttype_te;

   WaveDisp(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
   ~WaveDisp();

   void OnPaint( wxPaintEvent& WXUNUSED(event) );
   void render(void);

   void setSampleWords(uint32_t samplewords);

   void setHighlightType(hightlighttype_te type);

   void setStartPoint(uint32_t startpoint);
   void setEndPoint(uint32_t endpoint);

   void setSustainLoopStart(uint32_t pos);
   void setSustainLoopEnd(uint32_t pos);
   void setDisplaySustainLoop(bool flag);

   void setReleaseLoopStart(uint32_t pos);
   void setReleaseLoopEnd(uint32_t pos);
   void setDisplayReleaseLoop(bool flag);

   void setSampleData(uint16_t *ptr) { m_sample_data_u16 = ptr; };

   void zoomIn(void);
   void zoomOut(void);
   void resetZoom(void);

private:
   wxWindow *m_parent;
   wxSize m_size;
   hightlighttype_te hightlighttype_e;
   uint16_t *m_sample_data_u16;
   uint32_t m_sample_words;
   uint32_t m_start_point;
   uint32_t m_end_point;
   uint32_t m_sustainloop_start;
   uint32_t m_sustainloop_end;
   bool m_display_sustain_loop;
   uint32_t m_releaseloop_start;
   uint32_t m_releaseloop_end;
   bool m_display_release_loop;
   uint32_t m_width;
   uint32_t m_height;
   float m_zoom_scale;
   DECLARE_EVENT_TABLE()

   void OnMouseWheel(wxMouseEvent &event);
   void OnKeyEvent(wxKeyEvent &event);

};


#endif
