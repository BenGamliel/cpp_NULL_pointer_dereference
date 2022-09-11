//
// Created by Ben Gamliel on 11/09/2022.
//

#ifndef UNTITLED_REQUESTMESSAGE_H
#define UNTITLED_REQUESTMESSAGE_H
#pragma once
#include <string>
#include <cpprest/http_msg.h>

namespace Indigo
{
    class RequestMessage
    {
    public:
        void SetMethod(const web::http::method& method) { m_method = method; }
        void SetUri(const std::wstring& uri) { m_uri = uri; }
        void SetContent(const std::wstring& content);
        void SetContent(const std::vector<unsigned char>& content)
        { m_content = content; }
        void AddHeader(const std::wstring& key, const std::wstring& value)
        { m_headers[key] = value; }

        [[nodiscard]] const std::vector<unsigned char>& Getcontent() const
        { return m_content; }

        void PopulateJson(web::json::value& request) const;

        RequestMessage& operator=(const RequestMessage&) = default;
        bool operator==(const RequestMessage&) const;
    private:
        web::http::method m_method;
        std::wstring m_uri;
        std::vector<unsigned char> m_content;
        std::map<std::wstring, std::wstring> m_headers;
    };
}

#endif //UNTITLED_REQUESTMESSAGE_H
