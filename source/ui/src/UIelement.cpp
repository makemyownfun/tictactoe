#include "UIelement.h"

void UIelement::render(SDL_Renderer& renderer) {

    // blits the m_texture to the renderer
    // clip defines which part of the texture we're using
    // m_dest defines the x, y, w, and h of where we're putting it 
    SDL_RenderCopy(&renderer, m_texture->get(), &m_clip, &m_dest);
}